# Level00

    ~: ssh -p <PORT> level00@<IP of VM>
	Password: level00
    level00: find / -user flag00 2>/dev/null
    /usr/sbin/john
    level00: cat /usr/sbin/john
    cdiiddwpgswtgt
On passe la phrase par un decodeur cesar:
[](dcode.fr)
Cela nous donne : nottoohardhere

    level00: su flag00
    Password: nottoohardhere
    flag00: getflag
    x24ti5gi3x0ol2eh4esiuxias
    su level01
