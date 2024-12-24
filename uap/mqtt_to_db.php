<?php

require 'vendor/autoload.php';
use PhpMqtt\Client\MqttClient;
use PhpMqtt\Client\ConnectionSettings;

// Konfigurasi database
$host = 'localhost';
$dbname = 'mqtt_data';
$username = 'root'; // Sesuaikan username database Anda
$password = ''; // Sesuaikan password database Anda
$pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

// Konfigurasi MQTT
$server = '0b85d3df7164464d8dc9266234f24e9e.s1.eu.hivemq.cloud';
$port = 8883;
$mqtt_username = 'atmin';
$mqtt_password = 'Atmin123';
$clientId = 'PHPClient';

$connectionSettings = (new ConnectionSettings())
    ->setUsername($mqtt_username)
    ->setPassword($mqtt_password)
    ->setUseTls(true);

$mqtt = new MqttClient($server, $port, $clientId);
$mqtt->connect($connectionSettings, true);

// Subscribe ke topik yang dikirim oleh ESP32
$mqtt->subscribe('esp32/sensor/data', function ($topic, $message) use ($pdo) {
    echo "Received message on topic [$topic]: $message\n";

    // Decode JSON data
    $data = json_decode($message, true);
    if ($data) {
        $temperature = $data['suhu'];      // Suhu dari sensor
        $humidity = $data['kelembapan'];  // Kelembapan dari sensor
        $waterLevel = $data['water_level']; // Level air
        $rainDrop = $data['rain_drop'];    // Data hujan
        $ldrStatus = $data['ldr'];         // Status LDR (Gelap/Terang)

        // Insert data ke database
        $stmt = $pdo->prepare("
            INSERT INTO sensor_data (temperature, humidity, water_level, rain_drop, ldr_status) 
            VALUES (:temperature, :humidity, :waterLevel, :rainDrop, :ldrStatus)
        ");
        $stmt->execute([
            'temperature' => $temperature,
            'humidity' => $humidity,
            'waterLevel' => $waterLevel,
            'rainDrop' => $rainDrop,
            'ldrStatus' => $ldrStatus
        ]);
        echo "Data inserted to database\n";
    } else {
        echo "Invalid data format\n";
    }
}, 0);

// Loop untuk mendengarkan pesan MQTT
$mqtt->loop(true);
$mqtt->disconnect();
