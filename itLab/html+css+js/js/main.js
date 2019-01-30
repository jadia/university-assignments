function validateForm() {
    clearRequired(); // clear all previous alerts
    var flag = true;
    // username
    // if empty
    if (!document.getElementById('username').value) {
        document.getElementById('req_username').innerHTML = "*required field";
        flag = false;
    }

    // min length
    if (document.getElementById('username').length < 3) {
        document.getElementById('req_username').innerHTML = "Username length must be greater than 3.";
        flag = false;
    }

    // First name
    var flength = document.getElementById('Firstname').value.length;
    if (!document.getElementById('Firstname').value) {
        document.getElementById('req_Firstname').innerHTML = "*required field";
        flag = false;
    }

    // min and max length
    if (flength < 3 || flength > 15) {
        document.getElementById('req_Firstname').innerHTML = "Name should be atleast 3 and atmost 15 character long.";
        flag = false;
    }

    // alphabet check
    var firstNameValue = document.getElementById('Firstname').value;
    var alphabets = /^[a-zA-Z]+$/;
    if (!firstNameValue.match(alphabets)) {
        document.getElementById('req_Firstname').innerHTML = "Name should contain only alphabets.";
        flag = false;
    }


    // Last name
    if (!document.getElementById('Lastname').value) {
        document.getElementById('req_Lastname').innerHTML = "*required field";
        flag = false;
    }
    var llength = document.getElementById('Lastname').value.length;
    // min and max length
    if (llength < 3 || llength > 15) {
        document.getElementById('req_Lastname').innerHTML = "Name should be atleast 3 and atmost 15 character long.";
        flag = false;
    }
    // alphabet check
    var lastNameValue = document.getElementById('Lastname').value;
    var alphabets = /^[a-zA-Z]+$/;
    if (!lastNameValue.match(alphabets)) {
        document.getElementById('req_Lastname').innerHTML = "Name should contain only alphabets.";
        flag = false;
    }

    // email
    if (!document.getElementById('email').value) {
        document.getElementById('req_email').innerHTML = "*required field";
        flag = false;
    }

    // mobile
    var mobilevalue = document.getElementById('mobile').value;
    if (!mobilevalue) {
        document.getElementById('req_mobile').innerHTML = "*required field";
        flag = false;
    }

    if (isNaN(mobilevalue) || mobilevalue < 1 || mobilevalue.length < 10) {
        document.getElementById('req_mobile').innerHTML = "Please enter a valid Mobile number.";
        flag = false;
    }

    // password
    var passwd = document.getElementById('password').value;
    if (!passwd) {
        document.getElementById('req_password').innerHTML = "*required field";
        flag = false;
    }

    // password length
    if (passwd.length < 6) {
        document.getElementById('req_password').innerHTML = "Password cannot be less than 6 characters";
        flag = false;
    }
    // confirm password
    var confPasswd = document.getElementById('confirmPassword').value;
    if (!confPasswd) {
        document.getElementById('req_confirmPassword').innerHTML = "*required field";
        flag = false;
    }

    if (confPasswd.localeCompare(passwd)) {
        document.getElementById('req_confirmPassword').innerHTML = "Confirm password does not match";
        flag = false;
    }
    if (flag)
        return true;
    else
        return false;
}

function clearRequired() {
    var list = document.getElementsByClassName('required');
    var i;
    for (i = 0; i < list.length; i++) {
        list[i].innerHTML = "";
    }
}
