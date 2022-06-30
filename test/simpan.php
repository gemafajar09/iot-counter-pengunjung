<?php
include "koneksi.php";
$data = $_POST['data'];
$jumlah = $_POST['jumlah'];
$tgl = date('Y-m-d');

if($data != 0)
{
    $con->query("INSERT INTO `visitor`(`data`, `jumlah`, `tanggal`) VALUES ('$data','$jumlah','$tgl')");
    echo json_encode(['status' => 'ok']);
}else{
    echo json_encode(['status' => 'err']);
}
