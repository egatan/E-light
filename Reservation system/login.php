<?php
  header('Content-Type: text/html; charset=utf-8');
?>


<?php


if($_SESSION['id']==null) { // 로그인 하지 않았다면 아이디와 비밀번호 입력 화면으로

?>


<meta charset="utf-8">
<center><br><br><br>

<form name="login_form" action="signIn2.php" method="post">
	<br><br><br><br><br><br><br><br>

   <img src="logo3.png" width="280" height="110">
   <br>
   ID : <input type="text" name="id"><br>
   PW: <input type="password" name="pw"><br><br>
   <input type="submit" name="sub" value="Login">
	 <button type="button" onclick="location.href='join.php' ">Join</button>




</form>


</center>


<?php


}else{ // 로그인 했다면 초기 홈페이지 화면으로

   //echo "<script>location.href='home5.php';</script>";
  // echo ("<a href='home5.php?id=$id'>") ;


}

?>
