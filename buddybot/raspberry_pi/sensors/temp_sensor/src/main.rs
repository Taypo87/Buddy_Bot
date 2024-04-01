use dht11_gpio::{DHT11Controller, Sensor};

fn main() {
    const DHT11_PIN: u8 = 26;

    let mut sensor = DHT11Controller::new(DHT11_PIN).unwrap();

    let result = sensor.read_sensor_data();
    match result {
        Ok(data) => {
            println!("temperature: {} C", data.temperature);
            println!("humidity: {} %", data.humidity);
        }
        Err(err) => {
            println!("error: {}", err);
        }
    }
}

