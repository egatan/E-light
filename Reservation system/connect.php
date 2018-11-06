<?php
$con=mysql_connect("localhost","root","apmsetup");
mysql_query("set names utf8");
mysql_select_db("egatan",$con) or die(mysql_error($con));
error_reporting(E_ALL ^ E_NOTICE);

?>
