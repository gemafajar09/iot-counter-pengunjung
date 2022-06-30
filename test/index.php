<?php
$con = new mysqli('localhost','root','','test');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <center>Masuk</center>
    <br>
    <center><h5><div id="masuk"></div></h5></center>
    <br>
    <center>Keluar</center>
    <br>
    <center><h5><div id="keluar"></div></h5></center>

<script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
<script>
    setInterval(function () {
        real()
    }, 1000);

    function real()
    {
        $.ajax({
            url: "total.php",
            type: "GET",
            dataType: "JSON",
            success:function(res)
            {
                $('#masuk').html(res.masuk)
                $('#keluar').html(res.keluar)
            }
        })
    }
</script>
</body>
</html>
