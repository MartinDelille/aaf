#! C:/mksnt/sh.exe
#

CHECK_DEBUG=0
CHECK_RELEASE=0

#####################
# Parse Command Line
#####################
until [ $# = 0 ]
do
	case $1 in
		-r ) CHECK_RELEASE=1 ;;
		-d ) CHECK_DEBUG=1 ;;
		-h ) echo "\n-r = Release  -d = Debug"
			exit 1 ;;
	esac
	shift
done


DEBUG="AAFWinSDK/Debug"
RELEASE="AAFWinSDK/Release"

OLD_PATH=""

Status=0

RegisterTargetDLLs ()
{	
	Target=$1
	Options=$2

	print "Registering $Target $Options AAFPGAPI.dll"
	if regsvr32 ${Options} ./AAFWINSDK/${Target}/RefImpl/AAFPGAPI.dll
	then
		print "    Succeeded"
	else
		print "    Failed"
		exit -1
	fi

	print "Registering $Target $Options AAFCOAPI.dll"
	if regsvr32 ${Options} ./AAFWINSDK/${Target}/RefImpl/AAFCOAPI.dll
	then
		print "    Succeeded"
	else
		print "    Failed"
		exit -1
	fi

	print "Registering $Target $Options AAFINTP.dll "
	if regsvr32 ${Options} ./AAFWINSDK/${Target}/RefImpl/AAFINTP.dll
	then
		print "    Succeeded"
	else
		print "    Failed"
		exit -1
	fi
}


SetPath ()
{
	Target=$1

	print "\nSetting PATH $Target \n"
	OLD_PATH=$PATH
	PATH="`PWD`/AAFWINSDK/${Target}/RefImpl;$PATH"
}


ResetPath ()
{
	print "\nResetting PATH\n"
	PATH=$OLD_PATH
}


PrintSeparator ()
{
	print "\n\n\n\n"
}

RunExamples ()
{
	Target=$1

	START_DIR="`PWD`"

	cd AAFWinSDK/$Target

	cd Test
	cp ../../Test/Com/Laser.wav .
	ComModAAF

	PrintSeparator

	cd ../DevUtils
	cp ../Test/AAFSequenceTest.aaf .
	dump AAFSequenceTest.aaf

	PrintSeparator

	cd ../Examples/com
	COMClientAAF
	ComCutsTestAAF
	cp ../../../examples/com-api/ComEssenceDataTest/Laser.wav .
	ComEssenceDataTest
	ComPropDirectDump EssenceTest.aaf
	ComAAFInfo EssenceTest.aaf

	PrintSeparator

	cd ../../Utilities
	cp ../Test/AAFSequenceTest.aaf .
	AafOmf -omf AAFSequenceTest.aaf

	PrintSeparator

	cp D:/views/Complx2x.omf .
	AafOmf Complx2x.omf

	PrintSeparator

	cd $START_DIR
}



if [ CHECK_DEBUG -eq 1 ]; then
	SetPath "Debug"

	RegisterTargetDLLs "Debug" "/s"
	RunExamples "Debug"

	##UnRegister the DLLs##
	RegisterTargetDLLs "Debug" "/s /u"

	ResetPath
fi


if [ CHECK_RELEASE -eq 1 ]; then
	SetPath "Release"

	RegisterTargetDLLs "Release" "/s"
	RunExamples "Release"

	##UnRegister the DLLs##
	RegisterTargetDLLs "Release" "/s /u"

	ResetPath
fi
