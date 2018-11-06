<?php
  header('Content-Type: text/html; charset=utf-8');

 include('include/connect.php');

 $id=$_POST['id'];
 $pw=$_POST['pw'];
 $name=$_POST['name'];
 $age=$_POST['age'];
 $hp=$_POST['hp'];

 $sql = "SELECT * FROM user WHERE id = '{$id}'";
    $res = mysql_query($sql);
    if($res->num_rows >= 1){
        echo '이미 존재하는 아이디가 있습니다.';
        exit;
    }
    //닉네임, 생일 그리고 이름이 빈값이 아닌지
        if($name == '' || $hp == '' || $age == ''){
            echo '이름 혹은 연락처 혹은 나이의 값이 없습니다.';
            exit;
        }


        $sql = "INSERT INTO user VALUES('{$name}','{$id}','{$pw}','{$hp}','{$age}');";
        mysql_query($sql) or die (mysql_error($con));
        header('Location:login.php');
        // if($con->query($sql)){
        //        echo '회원가입 성공';
        //    }
       ?>
