################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# ����Щ���ߵ��õ�����������ӵ��������� 
C_SRCS += \
"../libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.c" 

COMPILED_SRCS += \
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.src" 

C_DEPS += \
"./libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.d" 

OBJS += \
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.o" 


# ÿ����Ŀ¼����Ϊ�����������׵�Դ�ṩ����
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.src":"../libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.c" "libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.o":"libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.src" "libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Sent-2f-Std

clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Sent-2f-Std:
	-$(RM) ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.d ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.o ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Sent/Std/IfxSent.src

.PHONY: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Sent-2f-Std

