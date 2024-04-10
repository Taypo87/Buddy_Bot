extern crate sdl2;
mod spi_controller;

use spi_controller::{MovementCommand, SpiController};
use std::error::Error;
use std::thread;
use std::time::Duration;

const DEAD_ZONE_X: i16 = 12000;
const DEAD_ZONE_Y: i16 = 12000;
const SENSITIVITY_THRESHOLD_X: i16 = 30000;
const SENSITIVITY_THRESHOLD_Y: i16 = 30000;
const BUFFER_ZONE: i16 = 6000;

fn main() -> Result<(), Box<dyn Error>> {
    let sdl_context = sdl2::init()?;
    let joystick_subsystem = sdl_context.joystick()?;

    let joystick = joystick_subsystem.open(0)?;
    let mut event_pump = sdl_context.event_pump()?;
    let mut spi_controller = SpiController::new("/dev/spidev0.0")?;

    let mut prev_axis_value_x = 0;
    let mut prev_axis_value_y = 0;

    'running: loop {
        let axis_value_x = joystick.axis(0)?;
        let axis_value_y = joystick.axis(1)?;

        if prev_axis_value_x != 0 || prev_axis_value_y != 0 {
            if axis_value_x.abs() < SENSITIVITY_THRESHOLD_X - DEAD_ZONE_X - BUFFER_ZONE
                && axis_value_y.abs() < SENSITIVITY_THRESHOLD_Y - DEAD_ZONE_Y - BUFFER_ZONE
            {
                spi_controller.send_command(MovementCommand::Stop, 0)?;
                prev_axis_value_x = 0;
                prev_axis_value_y = 0;
            }
        }

        if axis_value_x > SENSITIVITY_THRESHOLD_X && prev_axis_value_x == 0 {
            prev_axis_value_x = axis_value_x;
            spi_controller.send_command(MovementCommand::Right, 3)?;
        } else if axis_value_x < -SENSITIVITY_THRESHOLD_X && prev_axis_value_x == 0 {
            prev_axis_value_x = axis_value_x;
            spi_controller.send_command(MovementCommand::Left, 3)?;
        }

        if axis_value_y > SENSITIVITY_THRESHOLD_Y && prev_axis_value_y == 0 {
            prev_axis_value_y = axis_value_y;
            spi_controller.send_command(MovementCommand::Back, 3)?;
        } else if axis_value_y < -SENSITIVITY_THRESHOLD_Y && prev_axis_value_y == 0 {
            prev_axis_value_y = axis_value_y;
            spi_controller.send_command(MovementCommand::Forward, 3)?;
        }

        thread::sleep(Duration::from_millis(10));

        for event in event_pump.poll_iter() {
            use sdl2::event::Event;
            match event {
                Event::Quit { .. } => break 'running,
                _ => {}
            }
        }
    }

    Ok(())
}
