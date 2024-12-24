<?php
header('Content-Type: application/json');

// Konfigurasi database
$host = 'localhost';
$dbname = 'mqtt_data';
$username = 'root';
$password = '';

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Ambil data dari tabel
    $stmt = $pdo->query("SELECT * FROM sensor_data ORDER BY timestamp DESC");
    $data = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($data);
} catch (PDOException $e) {
    echo json_encode(['error' => $e->getMessage()]);
}
?>
