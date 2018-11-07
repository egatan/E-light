<?php
@header('P3P: CP="NOI CURa ADMa DEVa TAIa OUR DELa BUS IND PHY ONL UNI COM NAV INT DEM PRE"');
ini_set("session.cookie_domain",".webprogram.co.kr");  
session_start(); // 세션
include ("connect5.php"); // DB접속

mysql_query("set session character_set_connection=utf8;");

mysql_query("set session character_set_results=utf8;");

mysql_query("set session character_set_client=utf8;");

$id = $_POST['id']; // 아이디 
$pw = $_POST['pw']; // 패스워드
   
$query = "select * from manager where id='$id' and pw='$pw'";
$result = mysqli_query($con, $query); 
$row = mysqli_fetch_array($result);



if($id==$row['id'] && $pw==$row['pw']){ // id와 pw가 맞다면 login

   $_SESSION['id']=$row['id'];
   $_SESSION['name']=$row['name'];

   $getresult=mysqli_query($con,"select * from manager where id='$id'");
   while($row=mysqli_fetch_array($getresult)){
				$park=$row["Park"];
				
				$name=$row["Name"];
				
				$id=$row["id"];
				
				$pw=$row["pw"];
	} 
	echo ("<a href='home5.php?id=$id'>") ;
	//echo ("<a href='practice.php?id=$id'>") ;
	//echo ("<a href='practice2.html?id=$id'>") ;
    echo "<script>location.href='home5.php';</script>";

}else{ // id 또는 pw가 다르다면 login 폼으로

   echo "<script>window.alert('invalid username or password');</script>"; // 잘못된 아이디 또는 비빌번호 입니다
   echo "<script>location.href='login5.php';</script>";

}

?>