math.h 를 include 해서 사용하는 과정에서 
M_PI가 define돼있지 않다하여 _USE_MATH_DEFINES_ 를 define하여 사용하였고
cos, sin, atan2 등의 함수들이 reference가 존재하지 않는다하여 
g++로 compile하였다.

실행 환경은 WSL2 에서 실행하였으며
DISTRIB_ID=Ubuntu                                                                                                    DISTRIB_RELEASE=20.04                                                                                                DISTRIB_CODENAME=focal                                                                                               DISTRIB_DESCRIPTION="Ubuntu 20.04 LTS"                                                                               NAME="Ubuntu"                                                                                                        VERSION="20.04 LTS (Focal Fossa)"                                                                                    ID=ubuntu                                                                                                            ID_LIKE=debian                                                                                                       PRETTY_NAME="Ubuntu 20.04 LTS"                                                                                       VERSION_ID="20.04"   
위와 같다


최종 결과인 DFT 실행파일은 


	$ g++ DFT.c sample.c -o DFT
	
로 생성하였고 log.txt 파일은 

	$ ./DFT > log.txt

의 결과물이다. 

 
