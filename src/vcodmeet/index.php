<!DOCTYPE html>

<!-- index.php -->
<html xmlns="http://www.w3.org/1999/xhtml" lang="en-US" xml:lang="en-US">
    <head>
        <meta charset="UTF-8" />
        <title>v-CODE Meet Information</title>
        <link rel="stylesheet" type="text/css" href="css/style.css" />
    </head>

    <body spellcheck="false">
        <div id="superset">
            <h1>v-CODE Meet Information</h1>
<?php
    if (
        $_SERVER["REQUEST_METHOD"] === "POST" && strlen($_POST["username"]) >= 5
        && strlen($_POST["username"]) <= 100  && strlen($_POST["coming"]) === 1
    ) {
        $con = mysqli_connect("localhost", "vcodmeet", "vcodmeet", "vcodmeet");

        $username = mysqli_real_escape_string($con, $_POST["username"]);
        $coming   = mysqli_real_escape_string($con, $_POST["coming"]);
        $query = "insert into meetinfo (curtime, username, coming) ".
                    "values(now(), '$username', '$coming')";

        mysqli_query($con, $query);
        mysqli_close($con);
?>
            <h2>
                Thank you for contacting v-CODE.
            </h2>
<?php
    }
    else {
?>
            <form method="post"
                action="<?= htmlspecialchars($_SERVER["PHP_SELF"]) ?>"
                autocomplete="on">

                <h2>Will you be there at the meeting?</h2>
                <input type="radio" id="r0" name="coming" value="1"
                    required="required" />
                <label for="r0"><span><span></span></span>Yes</label>
                <br /><br />

                <input type="radio" id="r1" name="coming" value="0"
                    required="required" />
                <label for="r1"><span><span></span></span>No</label>
                <br /><br />

                <input placeholder="Name?" name="username" maxlength="100"
                    pattern="\w{5,100}" required="required"
                    title="Name (5 to 100 letters)" />
                <br /><br />

                <input class="button" type="submit" value="Done" />
            </form>
<?php
    }
?>
        </div>
    </body>
</html>
<!-- end of index.php -->
