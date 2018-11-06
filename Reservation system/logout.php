<?php
header("location:login.php");
session_start(); // 세션


//echo $_SESSION['id'].'님 로그아웃 하겠습니다.';

unset($_SESSION['id']);


if($_SESSION['id']!=null){
  echo "<script>location.href='login.php';</script>";
}



?>
