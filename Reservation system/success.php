<!-- <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title></head>

<body>
<div><h1>예약이 정상적으로 완료되었습니다.</h1></div>

</body>
</html> -->

<head>
	<title> E-Light </title>
	<meta charset="utf-8">


	<style>



	#div_root{
		margin: 	auto;
		width: 	800px;

	}

	#div_top{
		width: 	30%:
		height: 100px;
		text-align: 	left;
		float: left;
	}

	#div_hello{
		width: 	70%:
		height: 100px;
		text-align: 	left;
	}

	#div_menu{
		width: 	9%;
		height: 300px;

		text-align: 	center;
	}

	#div_line{
		width: 100%;
		height: 0px;
		float: left;

	}
	#div_con{
		width: 90%;
		height: 	300px;
		float:  center;
		text-align: 	center;
	}

	</style>
</head>


<body>

	<div id = div_top>
		<img src="logo3.png" width="280" height="110" onclick = "location.href='home5.php?id='$id'';">



	</div>



	<div id = div_hello>
		<div id="introduce">
			<br / ><br />
			<form action="signIn2.php" method="post">
				<?php
				session_start(); if(isset($_SESSION['id'])){ echo $_SESSION['id']; }

				?>님 안녕하세요!
			<!-- <a href='logout5.php'><input type='button' value='Logout'></a> -->
			<button
				type = "button"
				onclick = "location.href='reservation2.php';"
				style =  "color: #fff;
				background: skyblue;
				font-size:1.4em;
				border-radius:0.2em;
			  margin-left:380px;">예약하기</button>

				<button
					type = "button"
					onclick = "location.href='admin/adminpanal2.php';"
					style =  "color: #fff;
					background: skyblue;
					font-size:1.4em;
					border-radius:0.2em;
					margin-left:20px;
					margin-bottom:20px;
					">예약확인</button>
					<button
						type = "button"
						onclick = "location.href='logout.php';"
						style =  "color: #fff;
						background: skyblue;
						font-size:1.4em;
						border-radius:0.2em;
						margin-left:20px;
						margin-bottom:20px;
						">로그아웃</button>
		</div>


	</div>

	<hr>
  <br />
	<div id = "div_con" >
		<h1>예약이 정상적으로 완료되었습니다.</h1>

	</div>
</body>
