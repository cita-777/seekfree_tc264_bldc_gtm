################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# ����Щ���ߵ��õ�����������ӵ��������� 
C_SRCS += \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.c" \
"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.c" 

COMPILED_SRCS += \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.src" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.src" 

C_DEPS += \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.d" \
"./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.d" 

OBJS += \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.o" \
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.o" 


# ÿ����Ŀ¼����Ϊ�����������׵�Դ�ṩ����
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.src":"../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.c" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.o":"libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.src" "libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Math

clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Math:
	-$(RM) ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_AngleTrkF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Cf32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_Crc.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_BitReverseTable.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_FftF32_TwiddleTable.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_IntegralF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LowPassPt1F32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutAtan2F32_Table.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLSincosF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutLinearF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_LutSincosF32_Table.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_RampF32.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_BlackmanHarrisTable.src ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Math/Ifx_WndF32_HannTable.src

.PHONY: clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Math

