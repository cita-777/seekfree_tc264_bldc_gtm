################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# ����Щ���ߵ��õ�����������ӵ��������� 
C_SRCS += \
"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c" \
"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c" \
"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c" \
"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c" 

COMPILED_SRCS += \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src" 

C_DEPS += \
"./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d" \
"./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d" \
"./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d" \
"./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d" 

OBJS += \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o" \
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o" 


# ÿ����Ŀ¼����Ϊ�����������׵�Դ�ṩ����
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src":"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o":"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src":"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o":"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src":"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o":"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src":"../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o":"libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src" "libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-libraries-2f-infineon_libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

clean-libraries-2f-infineon_libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers:
	-$(RM) ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o ./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src

.PHONY: clean-libraries-2f-infineon_libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

