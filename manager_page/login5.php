<?php
@header('P3P: CP="NOI CURa ADMa DEVa TAIa OUR DELa BUS IND PHY ONL UNI COM NAV INT DEM PRE"');
ini_set("session.cookie_domain",".webprogram.co.kr"); 
session_start() ?>
<meta charset="utf-8">


<?php


if($_SESSION['id']==null) { // 로그인 하지 않았다면 아이디와 비밀번호 입력 화면으로 

?>


<meta charset="utf-8">
<center><br><br><br>

<form name="login_form" action="login_check5.php" method="post"> 
	<br><br><br><br><br><br><br><br>
   <img src="logo5.jpg" width="280" height="100"> 
   <br>
   ID : <input type="text" name="id"><br> 
   PW:<input type="password" name="pw"><br><br>
   <input type="submit" name="login" value="Login"> 
</form>
	

</center>


<?php


}else{ // 로그인 했다면 초기 홈페이지 화면으로

   //echo "<script>location.href='home5.php';</script>";
   echo ("<a href='home5.php?id=$id'>") ;

   
}

?>