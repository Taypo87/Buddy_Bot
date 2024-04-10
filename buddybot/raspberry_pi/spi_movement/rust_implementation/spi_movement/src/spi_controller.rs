extern crate spidev;

use spidev::{Spidev, SpidevOptions, SpiModeFlags};
use std::io;
use std::io::Write;

const SPEED: u32 = 1_000_000; // 1 MHz
const BITS_PER_WORD: u8 = 8;

#[derive(Debug)]
pub enum MovementCommand {
    Forward,
    Back,
    Left,
    Right,
    Stop,
}

#[repr(C)]
struct CmdPacket {
    command: u8, // 8 bits in total: 2 bits for speed, 6 bits for command
}

impl CmdPacket {
    fn new(command: MovementCommand, speed: u8) -> Self {
        let command_code = match command {
            MovementCommand::Forward => 0,
            MovementCommand::Back => 1,
            MovementCommand::Left => 2,
            MovementCommand::Right => 3,
            MovementCommand::Stop => 6,
        };
        let command = (speed & 0b11) | (command_code << 2); // Combine speed and command
        CmdPacket { command }
    }
}

pub struct SpiController {
    spi: Spidev,
}

impl SpiController {
    pub fn new(device: &str) -> io::Result<Self> {
        let mut spi = Spidev::open(device)?;
        let options = SpidevOptions::new()
            .bits_per_word(BITS_PER_WORD)
            .max_speed_hz(SPEED)
            .mode(SpiModeFlags::SPI_MODE_0)
            .build();
        spi.configure(&options)?;
        Ok(SpiController { spi })
    }

    pub fn send_command(&mut self, command: MovementCommand, speed: u8) -> io::Result<()> {
        let packet = CmdPacket::new(command, speed);
        self.spi.write(&[packet.command])?;
        Ok(())
    }
}
