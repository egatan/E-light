<?php
  header('Content-Type: text/html; charset=utf-8');
?>
<doctype html>
<html>
<head>
<title>sign up page</title>
</head>
<body>
  <center><br><br><br>
<form name="join" method="post" action="memberSave2.php">
  <br><br><br><br><br>
  <img src="logo3.png" width="280" height="110">
  <br>
 <table border="0" cellspacing="0" cellpadding="3">
  <tr>
   <td>ID     </td>
   <td><input type="text" size="30" name="id"></td>
  </tr>
  <tr>
   <td>Password</td>
   <td><input type="password" size="30" name="pw"></td>
  </tr>

  <tr>
   <td>Name</td>
   <td><input type="text" size="12" maxlength="10" name="name"></td>
  </tr>
  <tr>
   <td> Age</td>
   <td><input type="text" size="6" name="age"></td>
  </tr>
  <tr>
   <td>HP</td>
   <td><input type="text" size="30" maxlength="12" name="hp"></td>
  </tr>


 </table>
 <br>
 <input type=submit name="sub" value="join">
 <!-- <button type="button" onclick="location.href='login.php' ">Submit</button> -->

</form>
</center>
</body>
</html>
