/*
 * SAMSUNG NFC N2 Controller
 *
 * Copyright (C) 2013 Samsung Electronics Co.Ltd
 * Author: Woonki Lee <woonki84.lee@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the License, or (at your
 * option) any later version.
 *
 */

#define SEC_NFC_DRIVER_NAME		"sec-nfc"
#define SEC_NFC_FN_DRIVER_NAME		"sec-nfc-fn"

#define SEC_NFC_MAX_BUFFER_SIZE	512

/* ioctl */
#define SEC_NFC_MAGIC	'S'
#define SEC_NFC_GET_MODE		_IOW(SEC_NFC_MAGIC, 0, unsigned int)
#define SEC_NFC_SET_MODE		_IOW(SEC_NFC_MAGIC, 1, unsigned int)
#define SEC_NFC_GET_PUSH		_IOW(SEC_NFC_MAGIC, 2, unsigned int)
#define SEC_NFC_SET_UART_STATE		_IOW(SEC_NFC_MAGIC, 3, unsigned int)

/* size */
#define SEC_NFC_MSG_MIN_SIZE	1
#define SEC_NFC_MSG_MAX_SIZE	(256 + 4)

/* wait for device stable */
#define SEC_NFC_VEN_WAIT_TIME	(100)

/* gpio pin configuration */
struct sec_nfc_platform_data {
	unsigned int irq;
	unsigned int ven;
	unsigned int firm;
	void	(*cfg_gpio)(void);
};

#ifdef CONFIG_SEC_NFC_S3FNRN5
enum sec_nfc_state {
	SEC_NFC_ST_NORM = 0,
	SEC_NFC_ST_OFF,
	SEC_NFC_ST_FIRM,
	SEC_NFC_ST_SLEEP,
	SEC_NFC_ST_WAKEUP,
	SEC_NFC_ST_COUNT,
};
#else
#define STATE_FIRM_HIGH	1
#define STATE_FIRM_LOW	0

enum sec_nfc_state {
	SEC_NFC_ST_OFF = 0,
	SEC_NFC_ST_NORM,
	SEC_NFC_ST_FIRM,
	SEC_NFC_ST_COUNT,
};

enum sec_nfc_uart_state {
	SEC_NFC_ST_UART_OFF = 0,
	SEC_NFC_ST_UART_ON,

};
#endif

#ifdef CONFIG_SEC_NFC_S3FNRN3_FN
struct sec_nfc_fn_platform_data {
	unsigned int push;
	void    (*cfg_gpio)(void);
};

enum readable_state {
    RDABLE_NULL = 0,
    RDABLE_NO,
    RDABLE_PENDING,
    RDABLE_YES,
};
#endif

