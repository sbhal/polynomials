import os
import glob
import time
import subprocess

rootdir = os.getcwd()
dirlist = os.path.join(rootdir, "dirlist.txt")

rootDir = '.'
for dirName, subdirList, fileList in os.walk(rootDir):
    print('Found directory: %s' % dirName)
    if "Submission" in dirName:
        os.chdir(dirName)
        commentfile = os.path.join(os.path.abspath(os.path.join(os.getcwd(), os.pardir)), "comments.txt")
        subprocess.call('start notepad++ ' + commentfile, shell=True)
        for cppfile in glob.glob("*.cpp"):
            subprocess.call('start notepad++ ' + cppfile, shell=True)
            input('Press Enter for next file')

        os.chdir(os.pardir)
        os.chdir(os.pardir)		
