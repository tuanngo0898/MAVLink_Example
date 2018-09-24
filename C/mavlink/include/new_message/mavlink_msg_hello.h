#pragma once
// MESSAGE HELLO PACKING

#define MAVLINK_MSG_ID_HELLO 0

MAVPACKED(
typedef struct __mavlink_hello_t {
 float float_num; /*< [u] A int8_number.*/
 uint16_t int16_num; /*< [u] A int16_number.*/
 uint8_t type; /*<  Type of message.*/
 uint8_t int8_num; /*< [u] A int8_number.*/
}) mavlink_hello_t;

#define MAVLINK_MSG_ID_HELLO_LEN 8
#define MAVLINK_MSG_ID_HELLO_MIN_LEN 8
#define MAVLINK_MSG_ID_0_LEN 8
#define MAVLINK_MSG_ID_0_MIN_LEN 8

#define MAVLINK_MSG_ID_HELLO_CRC 70
#define MAVLINK_MSG_ID_0_CRC 70



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HELLO { \
    0, \
    "HELLO", \
    4, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_hello_t, type) }, \
         { "int8_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_hello_t, int8_num) }, \
         { "int16_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_hello_t, int16_num) }, \
         { "float_num", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_hello_t, float_num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HELLO { \
    "HELLO", \
    4, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_hello_t, type) }, \
         { "int8_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_hello_t, int8_num) }, \
         { "int16_num", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_hello_t, int16_num) }, \
         { "float_num", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_hello_t, float_num) }, \
         } \
}
#endif

/**
 * @brief Pack a hello message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Type of message.
 * @param int8_num [u] A int8_number.
 * @param int16_num [u] A int16_number.
 * @param float_num [u] A int8_number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hello_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t int8_num, uint16_t int16_num, float float_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HELLO_LEN];
    _mav_put_float(buf, 0, float_num);
    _mav_put_uint16_t(buf, 4, int16_num);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, int8_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HELLO_LEN);
#else
    mavlink_hello_t packet;
    packet.float_num = float_num;
    packet.int16_num = int16_num;
    packet.type = type;
    packet.int8_num = int8_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HELLO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HELLO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
}

/**
 * @brief Pack a hello message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  Type of message.
 * @param int8_num [u] A int8_number.
 * @param int16_num [u] A int16_number.
 * @param float_num [u] A int8_number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hello_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t int8_num,uint16_t int16_num,float float_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HELLO_LEN];
    _mav_put_float(buf, 0, float_num);
    _mav_put_uint16_t(buf, 4, int16_num);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, int8_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HELLO_LEN);
#else
    mavlink_hello_t packet;
    packet.float_num = float_num;
    packet.int16_num = int16_num;
    packet.type = type;
    packet.int8_num = int8_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HELLO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HELLO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
}

/**
 * @brief Encode a hello struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hello C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hello_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hello_t* hello)
{
    return mavlink_msg_hello_pack(system_id, component_id, msg, hello->type, hello->int8_num, hello->int16_num, hello->float_num);
}

/**
 * @brief Encode a hello struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hello C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hello_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hello_t* hello)
{
    return mavlink_msg_hello_pack_chan(system_id, component_id, chan, msg, hello->type, hello->int8_num, hello->int16_num, hello->float_num);
}

/**
 * @brief Send a hello message
 * @param chan MAVLink channel to send the message
 *
 * @param type  Type of message.
 * @param int8_num [u] A int8_number.
 * @param int16_num [u] A int16_number.
 * @param float_num [u] A int8_number.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hello_send(mavlink_channel_t chan, uint8_t type, uint8_t int8_num, uint16_t int16_num, float float_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HELLO_LEN];
    _mav_put_float(buf, 0, float_num);
    _mav_put_uint16_t(buf, 4, int16_num);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, int8_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HELLO, buf, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
#else
    mavlink_hello_t packet;
    packet.float_num = float_num;
    packet.int16_num = int16_num;
    packet.type = type;
    packet.int8_num = int8_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HELLO, (const char *)&packet, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
#endif
}

/**
 * @brief Send a hello message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hello_send_struct(mavlink_channel_t chan, const mavlink_hello_t* hello)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hello_send(chan, hello->type, hello->int8_num, hello->int16_num, hello->float_num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HELLO, (const char *)hello, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
#endif
}

#if MAVLINK_MSG_ID_HELLO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hello_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t int8_num, uint16_t int16_num, float float_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, float_num);
    _mav_put_uint16_t(buf, 4, int16_num);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, int8_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HELLO, buf, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
#else
    mavlink_hello_t *packet = (mavlink_hello_t *)msgbuf;
    packet->float_num = float_num;
    packet->int16_num = int16_num;
    packet->type = type;
    packet->int8_num = int8_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HELLO, (const char *)packet, MAVLINK_MSG_ID_HELLO_MIN_LEN, MAVLINK_MSG_ID_HELLO_LEN, MAVLINK_MSG_ID_HELLO_CRC);
#endif
}
#endif

#endif

// MESSAGE HELLO UNPACKING


/**
 * @brief Get field type from hello message
 *
 * @return  Type of message.
 */
static inline uint8_t mavlink_msg_hello_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field int8_num from hello message
 *
 * @return [u] A int8_number.
 */
static inline uint8_t mavlink_msg_hello_get_int8_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field int16_num from hello message
 *
 * @return [u] A int16_number.
 */
static inline uint16_t mavlink_msg_hello_get_int16_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field float_num from hello message
 *
 * @return [u] A int8_number.
 */
static inline float mavlink_msg_hello_get_float_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a hello message into a struct
 *
 * @param msg The message to decode
 * @param hello C-struct to decode the message contents into
 */
static inline void mavlink_msg_hello_decode(const mavlink_message_t* msg, mavlink_hello_t* hello)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    hello->float_num = mavlink_msg_hello_get_float_num(msg);
    hello->int16_num = mavlink_msg_hello_get_int16_num(msg);
    hello->type = mavlink_msg_hello_get_type(msg);
    hello->int8_num = mavlink_msg_hello_get_int8_num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HELLO_LEN? msg->len : MAVLINK_MSG_ID_HELLO_LEN;
        memset(hello, 0, MAVLINK_MSG_ID_HELLO_LEN);
    memcpy(hello, _MAV_PAYLOAD(msg), len);
#endif
}
