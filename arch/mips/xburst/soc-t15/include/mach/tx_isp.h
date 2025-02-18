#ifndef __TX_ISP_H__
#define __TX_ISP_H__

#include <linux/videodev2.h>
#include <linux/v4l2-mediabus.h>
#define TX_SENSOR_MAX_REGULATOR_NUM 3
#define DUMMY_CLOCK_RATE 0x0000ffff

#define TX_ISP_EXIST_CSI_DEVICE 1
#define TX_ISP_EXIST_DS2_CHANNEL 1

#define TX_ISP_INPUT_PORT_MAX_WIDTH		2688
#define TX_ISP_INPUT_PORT_MAX_HEIGHT	2048
#define TX_ISP_FR_CHANNEL_MAX_WIDTH		2688
#define TX_ISP_FR_CHANNEL_MAX_HEIGHT	2048
#define TX_ISP_DS1_CHANNEL_MAX_WIDTH	1920
#define TX_ISP_DS1_CHANNEL_MAX_HEIGHT	1080
#if TX_ISP_EXIST_DS2_CHANNEL
#define TX_ISP_DS2_CHANNEL_MAX_WIDTH	1280
#define TX_ISP_DS2_CHANNEL_MAX_HEIGHT	720
#endif
/*
* The subdevices's group IDs.
*/

enum tx_isp_subdev_group_index {
	TX_ISP_CORE_GRP_IDX,
	TX_ISP_VIC_GRP_IDX,
	TX_ISP_CSI_GRP_IDX,
	TX_ISP_VIDEO_IN_GRP_IDX,
	TX_ISP_MAX_GRP_IDX,
};

/*
* the names of subdev are defined here.
*/
#define TX_ISP_CSI_NAME "tx-isp-csi"
#define TX_ISP_VIC_NAME "tx-isp-vic"
#define TX_ISP_CORE_NAME "tx-isp-core"

/*
* the return values are defined here.
*/
#define ISP_SUCCESS 0
#define ISP_ERROR   0xfe

/*
@ name: the clock's name
@ rate: the rate of the clock.
@ flags:
*/
struct tx_isp_subdev_clk_info{
	const char *name;
	unsigned long rate;
};
/*
@ name : sensor's name
@ rst_gpio: the number of gpio that reset sensor; the invalid value is -1.
@ pwdn_gpio: the number of gpio that power down sensor; the invalid value is -1.
@ mclk_gpio : the name of sensor's mclk
@ regulator_name : the name of sensor's power
*/
struct tx_isp_sensor_board_info{
	const char *name;
	unsigned int reset_gpio;
	unsigned int pwdn_gpio;
	const char *mclk_name;
	const char *regulator_name[TX_SENSOR_MAX_REGULATOR_NUM];
};

struct tx_isp_sensor_video_setting{
	struct v4l2_mbus_framefmt mbus;
	struct v4l2_fract interval;
	void *param;
};

struct tx_isp_subdev_platform_data {
	unsigned int grp_id;
	struct tx_isp_subdev_clk_info *clks;
	unsigned int clk_num;
};

#endif /*__TX_ISP_H__*/
