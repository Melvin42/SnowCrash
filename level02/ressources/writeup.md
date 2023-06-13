# Level02

    level02: ls -al
    level02.pcap

On copie ce fichier dans notre ordinateur pour l'analyser  avec cette commande:

    melperri: scp -P 4242 level02@192.168.1.3:/home/user/level02/level02.pcap melperri@127.0.0.1 /home/melperri
    level02.pcap done
    melperri: tcpick -C -yP -r level02.pcap
    ft_wandr...NDRel.L0L
Les points representent des Backspace, le mdp de flag02 est donc:

    level02: su flag02
    Password: ft_waNDReLOL
    flag02: getflag
    kooda2puivaav1idi4f57q8iq
