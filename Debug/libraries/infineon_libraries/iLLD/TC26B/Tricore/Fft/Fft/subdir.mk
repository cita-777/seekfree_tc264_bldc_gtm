################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
"../libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.c" 

COMPILED_SRCS += \
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.src" 

C_DEPS += \
"./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.d" 

OBJS += \
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.o" 


# 每个子目录必须为构建它所贡献的源提供规则
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.src":"../libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.c" "libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/【源码】下载到驱动板的源码/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.o":"libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.src" "libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Fft-2f-Fft

clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Fft-2f-Fft:
	-$(RM) ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.d ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.o ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fft/Fft/IfxFft_Fft.src

.PHONY: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Fft-2f-Fft

