################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
"../code/hardware/adc.c" \
"../code/hardware/gpio.c" \
"../code/hardware/move_filter.c" \
"../code/hardware/pwm_input.c" 

COMPILED_SRCS += \
"code/hardware/adc.src" \
"code/hardware/gpio.src" \
"code/hardware/move_filter.src" \
"code/hardware/pwm_input.src" 

C_DEPS += \
"./code/hardware/adc.d" \
"./code/hardware/gpio.d" \
"./code/hardware/move_filter.d" \
"./code/hardware/pwm_input.d" 

OBJS += \
"code/hardware/adc.o" \
"code/hardware/gpio.o" \
"code/hardware/move_filter.o" \
"code/hardware/pwm_input.o" 


# 每个子目录必须为构建它所贡献的源提供规则
"code/hardware/adc.src":"../code/hardware/adc.c" "code/hardware/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/【源码】下载到驱动板的源码/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/hardware/adc.o":"code/hardware/adc.src" "code/hardware/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/hardware/gpio.src":"../code/hardware/gpio.c" "code/hardware/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/【源码】下载到驱动板的源码/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/hardware/gpio.o":"code/hardware/gpio.src" "code/hardware/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/hardware/move_filter.src":"../code/hardware/move_filter.c" "code/hardware/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/【源码】下载到驱动板的源码/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/hardware/move_filter.o":"code/hardware/move_filter.src" "code/hardware/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/hardware/pwm_input.src":"../code/hardware/pwm_input.c" "code/hardware/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/【源码】下载到驱动板的源码/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/hardware/pwm_input.o":"code/hardware/pwm_input.src" "code/hardware/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-code-2f-hardware

clean-code-2f-hardware:
	-$(RM) ./code/hardware/adc.d ./code/hardware/adc.o ./code/hardware/adc.src ./code/hardware/gpio.d ./code/hardware/gpio.o ./code/hardware/gpio.src ./code/hardware/move_filter.d ./code/hardware/move_filter.o ./code/hardware/move_filter.src ./code/hardware/pwm_input.d ./code/hardware/pwm_input.o ./code/hardware/pwm_input.src

.PHONY: clean-code-2f-hardware

