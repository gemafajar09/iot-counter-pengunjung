<?php
$con = new mysqli('localhost','root','','test');

$masuk = $con->query("SELECT count(*) as total FROM visitor WHERE `data` = 1")->fetch_assoc();
$keluar = $con->query("SELECT count(*) as total FROM visitor WHERE `data` = 2")->fetch_assoc();
$data = array(
    'masuk' => $masuk['total'],
    'keluar' => $keluar['total'],
);
echo json_encode($data);