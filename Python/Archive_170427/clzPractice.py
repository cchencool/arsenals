#!/usr/bin/python

import pexpect
import sys
import time
import os

now = time.strftime("%m%d%y_%I%M%S%p", time.localtime())

if sys.argv[1] == '-c':
    foo = pexpect.spawn('scp -r %s user@address.org:/home/user/' % sys.argv[2])
    foo.expect('.ssword:*')
    foo.sendline('password')
    foo.interact()

elif sys.argv[1] == '-b':
    os.mkdir("/home/user/BKUP/foo.com%s" % now, 0x700)
    foo = pexpect.spawn('scp -r user@foo.org:/RemoteBox/user/%s /LocalBox/user/Bup/foo%s/' % (sys.argv[2], now))
    foo.expect('.*ssword:')
    foo.sendline('Passwd_to_server')
    foo.interact()
elif sys.argv[1] == '-p':
    foo = pexpect.spawn('ssh foo@bar.com')
    foo.expect('.*')
    foo.sendline('password')
    foo.interact()
else:
    foo = pexpect.spawn('ssh default@default.org')
    foo.expect('.*ssword:')
    foo.sendline('password')
    foo.interact()
