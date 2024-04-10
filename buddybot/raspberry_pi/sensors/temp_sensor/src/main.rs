use dht11_gpio::{DHT11Controller, Sensor};
use mongodb::{
    bson::{doc, Document},
    error::Error,
    Client,
};

// Define a struct to represent sensor data
#[derive(Debug)]
struct SensorData {
    sensor_id: String,
    temperature: f64,
    humidity: f64,
}

impl SensorData {
    // Convert SensorData to a BSON Document for MongoDB
    fn to_document(&self) -> Document {
        doc! {
            "sensor_id": &self.sensor_id,
            "temperature": &self.temperature,
            "humidity": &self.humidity,
        }
    }
}

// Define a struct to represent the MongoDB database
struct Database {
    client: Client,
}

impl Database {
    // Connect to the MongoDB server
    async fn new(uri: &str) -> Result<Self, Error> {
        let client = Client::with_uri_str(uri).await?;
        Ok(Database { client })
    }

    // Insert sensor data into the MongoDB collection
    async fn insert_sensor_data(&self, db_name: &str, collection_name: &str, sensor_data: SensorData) -> Result<(), Error> {
        let database = self.client.database(db_name);
        let collection = database.collection(collection_name);
        collection.insert_one(sensor_data.to_document(), None).await?;
        Ok(())
    }
}

#[tokio::main]
async fn main() -> Result<(), Error> {
    // Connect to MongoDB
    let database = Database::new("mongodb+srv://oladelemiro07:iu5sFIozHXZS1Diw@cluster0.ksqjuru.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0").await?;

    const DHT11_PIN: u8 = 26;

    let mut sensor = DHT11Controller::new(DHT11_PIN).unwrap();

    let result = sensor.read_sensor_data();
    match result {
        Ok(data) => {
            let sensor_data = SensorData {
                sensor_id: "tempAndHumid".to_string(),
                temperature: data.temperature,
                humidity: data.humidity,
            };
            database.insert_sensor_data("sensors", "sensor_data", sensor_data).await?;
    }
    Err(err) => {
        println!("Error reading sensor data: {}", err);
    }
}

    println!("Sensor data inserted successfully!");

    Ok(())
}

