################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# ����Щ���ߵ��õ�����������ӵ��������� 
C_SRCS += \
"../code/bldc/gtm_pwm.c" \
"../code/bldc/motor.c" 

COMPILED_SRCS += \
"code/bldc/gtm_pwm.src" \
"code/bldc/motor.src" 

C_DEPS += \
"./code/bldc/gtm_pwm.d" \
"./code/bldc/motor.d" 

OBJS += \
"code/bldc/gtm_pwm.o" \
"code/bldc/motor.o" 


# ÿ����Ŀ¼����Ϊ�����������׵�Դ�ṩ����
"code/bldc/gtm_pwm.src":"../code/bldc/gtm_pwm.c" "code/bldc/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/bldc/gtm_pwm.o":"code/bldc/gtm_pwm.src" "code/bldc/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"code/bldc/motor.src":"../code/bldc/motor.c" "code/bldc/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc26xb "-fD:/Desktop/TC264_GTM_BLDC_Project-master/TC264_GTM_BLDC_Project-master/��Դ�롿���ص��������Դ��/seekfree_tc264_bldc_gtm/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<"
"code/bldc/motor.o":"code/bldc/motor.src" "code/bldc/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-code-2f-bldc

clean-code-2f-bldc:
	-$(RM) ./code/bldc/gtm_pwm.d ./code/bldc/gtm_pwm.o ./code/bldc/gtm_pwm.src ./code/bldc/motor.d ./code/bldc/motor.o ./code/bldc/motor.src

.PHONY: clean-code-2f-bldc

