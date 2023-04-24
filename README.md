# SnowCrash
## Setting up the environment
First download the SnowCrash.iso from the intra42
Then on Virtual Box click on the New button:
![](https://github.com/Raiklan/SnowCrash/blob/main/Screenshot%20from%202023-04-24%2015-15-40.png)
Now choose Linux as OS and Oracle-64bit as Version
![](https://github.com/Raiklan/SnowCrash/blob/main/Screenshot%20from%202023-04-24%2016-06-58.png)
Then click next as many times as needed then launch the SnowCrash VM:
Select the path to the iso.
Now stop the VM and in the Network settings, go to Port Forwarding and Add a new one:
127.0.0.1 8080 10.0.2.15 4242
Now relaunch the VM and we are good to go !
