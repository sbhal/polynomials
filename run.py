import os
import shutil
import time
import subprocess
import signal

envfile = r"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat"

rootdir = os.getcwd()
in1 = os.path.join(rootdir, "in1.txt")
in2 = os.path.join(rootdir, "in2.txt")
in3 = os.path.join(rootdir, "in3.txt")

# Set the directory you want to start from
rootDir = '.'
for dirName, subdirList, fileList in os.walk(rootDir):
    print('Found directory: %s' % dirName)
    if "Submission" in dirName:
        os.chdir(dirName)
        print "\n\t\t\tENTERED------->\n" + os.getcwd()
        commentfile = os.path.join(os.path.abspath(os.path.join(os.getcwd(), os.pardir)), "comments.txt")
        
        subprocess.Popen(['notepad++ ', commentfile])
        #subprocess.Popen(["call", envfile], shell=True)
        shutil.copy(in1, os.getcwd())
        shutil.copy(in2, os.getcwd())
        shutil.copy(in3, os.getcwd())

        #os.system('cd')

        os.system(r'"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat" && cl.exe /ZI /W3 /WX- /sdl /Od /Oy- /D WIN32 /D _DEBUG /D _CONSOLE /D _UNICODE /D UNICODE /Gm /EHsc /RTC1 /MDd /GS /fp:precise /Zc:forScope /Zc:inline /Gd /TP *.cpp /Fe:main.exe')

        cppfile = os.path.join(os.getcwd(), "matrix_creator.cpp")
        if os.path.exists(cppfile):
            subprocess.Popen(['notepad++ ', cppfile])
        else:
            print("No"+ cppfile +" file present")

        exefile = os.path.join(os.getcwd(), "main.exe")
        
        if os.path.exists(exefile):
            print("\n\n\t\t\tExec compute-poly.exe in1.txt out1.txt\n")
            task1 = subprocess.Popen('main.exe in1.txt out1.txt')
            time.sleep(1.0)
            task1.terminate()
            task1.kill()
            out1 = os.path.join(os.getcwd(), "out1.txt")
            if os.path.exists(out1):
                os.system('type out1.txt')
            else:
                print "No out1.txt file"

            print("\n\n\t\t\t Exec compute-poly.exe in2.txt out2.txt\n")
            task2 = subprocess.Popen('main.exe in2.txt out2.txt')
            time.sleep(1.0)
            task2.terminate()
            task2.kill()
            out2 = os.path.join(os.getcwd(), "out2.txt")
            
            if os.path.exists(out2):
                os.system('type out2.txt')
            else:
                print "No out2.txt file"

            print("\n\n\t\t\t Exec compute-poly.exe in3.txt out3.txt\n")
            task3 = subprocess.Popen('main.exe in3.txt out3.txt')
            time.sleep(1.0)
            task3.terminate()
            task3.kill()
            out3 = os.path.join(os.getcwd(), "out3.txt")
            if os.path.exists(out3):
                os.system('type out3.txt')
            else:
                print "No out3.txt file"

        else:
            print "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!---NO EXEC FILE---!!!!!!!!!!!!!!!!!!!!!\n"

        
        raw_input("Press Enter to continue...")
        print "---<<----EXIT-----<<--" + os.getcwd()
        os.system("cls")
        os.chdir(os.pardir)
        os.chdir(os.pardir)
