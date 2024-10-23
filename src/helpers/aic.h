#pragma once

#include <furi.h>

static uint8_t S_BOX_INV[9][256] = {
    {0x24, 0x3c, 0xba, 0x36, 0xe3, 0x85, 0xa4, 0xd0, 0x93, 0x43, 0x73, 0xb9, 0x70, 0x6e, 0xc9,
     0xf1, 0x10, 0x0e, 0x9b, 0x2c, 0x97, 0xe7, 0x0b, 0x63, 0x6c, 0x29, 0x20, 0xfe, 0x86, 0xf3,
     0xe1, 0xf5, 0xf6, 0x9f, 0xb6, 0x16, 0x04, 0x7b, 0x8f, 0xab, 0xb1, 0x39, 0x2a, 0x1b, 0xeb,
     0x5c, 0xa8, 0xac, 0x38, 0x11, 0x12, 0x5f, 0x89, 0x3e, 0x7d, 0xca, 0xec, 0x53, 0xdb, 0x6d,
     0x1e, 0xd2, 0x81, 0x78, 0x96, 0x46, 0xff, 0xf9, 0x54, 0x1c, 0x28, 0x7a, 0x4f, 0xd3, 0xc0,
     0xdc, 0xc1, 0x6a, 0xf2, 0xbc, 0xcb, 0x57, 0xfd, 0x4a, 0xe4, 0xf0, 0xb2, 0xc7, 0x95, 0x40,
     0x62, 0x52, 0x41, 0xe2, 0xad, 0x49, 0xa6, 0xb5, 0x1f, 0x02, 0xc8, 0xda, 0x92, 0xe5, 0xb0,
     0xc5, 0x64, 0x76, 0x48, 0x21, 0xde, 0x0f, 0x45, 0x58, 0x4c, 0xdf, 0xa7, 0x84, 0xcf, 0xd5,
     0x15, 0x4e, 0x27, 0x80, 0x6b, 0x7f, 0xfc, 0x44, 0x71, 0x47, 0x22, 0xdd, 0x30, 0x0c, 0xa1,
     0x3b, 0xe0, 0x37, 0xa0, 0x35, 0x23, 0x90, 0x32, 0x74, 0xbf, 0x8d, 0xc2, 0xea, 0xd6, 0x50,
     0xbb, 0xd9, 0xc4, 0x83, 0xb4, 0x31, 0x68, 0x55, 0x8b, 0x5d, 0xf4, 0x72, 0x18, 0xb7, 0xef,
     0xf7, 0x98, 0x2d, 0x01, 0x03, 0x61, 0xcc, 0x0a, 0x8e, 0x13, 0x00, 0xe8, 0x14, 0xaf, 0x09,
     0x51, 0x75, 0xa5, 0x2f, 0x1d, 0x0d, 0x65, 0x8a, 0xcd, 0x66, 0x07, 0x3d, 0x05, 0xd8, 0x4b,
     0xe9, 0x9d, 0x99, 0x7c, 0x91, 0xd1, 0xb8, 0x19, 0xc3, 0x2b, 0x42, 0x69, 0x88, 0xc6, 0x79,
     0x17, 0x3a, 0x4d, 0x5b, 0xa2, 0x5a, 0xfb, 0x25, 0x3f, 0xbd, 0xf8, 0xed, 0xce, 0xe6, 0x87,
     0xa3, 0x26, 0xa9, 0x2e, 0xbe, 0x94, 0x08, 0x7e, 0x67, 0x60, 0x8c, 0x9c, 0x5e, 0x6f, 0xb3,
     0x9e, 0x06, 0xfa, 0x82, 0xae, 0xee, 0x59, 0x77, 0xd7, 0x1a, 0x9a, 0x34, 0xd4, 0x56, 0xaa,
     0x33},
    {0xf9, 0x81, 0x7c, 0x00, 0xb9, 0x30, 0x37, 0xd5, 0x90, 0x51, 0x6e, 0xf0, 0xb2, 0x06, 0xfb,
     0xcd, 0x39, 0x14, 0x5f, 0xf8, 0x1b, 0xc7, 0x4a, 0x82, 0x70, 0x8c, 0x92, 0x1d, 0xea, 0xc3,
     0x4e, 0xc8, 0x12, 0xe6, 0xb6, 0x10, 0xd3, 0x2f, 0x95, 0x84, 0x25, 0x42, 0xa5, 0x72, 0xe5,
     0x8f, 0x55, 0xef, 0x86, 0xa2, 0x53, 0xae, 0xed, 0x26, 0x20, 0x47, 0xde, 0x78, 0x68, 0x28,
     0xe4, 0x45, 0xcc, 0x35, 0xbc, 0x3e, 0xbb, 0x8e, 0xc0, 0xbe, 0x34, 0xaf, 0xa6, 0x09, 0x64,
     0x01, 0x7b, 0x44, 0xf5, 0xf3, 0xb1, 0x3f, 0xa4, 0xb3, 0x32, 0x80, 0xc9, 0x4f, 0x6f, 0x40,
     0xbf, 0x21, 0x4c, 0x74, 0xe1, 0x11, 0x5e, 0xeb, 0x3d, 0x71, 0x2e, 0x9d, 0x62, 0x75, 0xd4,
     0x16, 0x48, 0x77, 0x13, 0x67, 0xad, 0x6b, 0x5d, 0x07, 0x87, 0xf7, 0xa8, 0x9a, 0x59, 0x76,
     0x8b, 0x9b, 0x1e, 0xd8, 0xee, 0xaa, 0xe9, 0x99, 0x2d, 0xc5, 0x97, 0xf1, 0xa7, 0x83, 0xfc,
     0xca, 0xdc, 0xba, 0xb8, 0x4b, 0xe8, 0x89, 0x17, 0x05, 0x0b, 0xa0, 0x65, 0x23, 0xd1, 0xce,
     0x36, 0x03, 0xd7, 0xe0, 0xf2, 0x91, 0xdf, 0x0e, 0x9c, 0x2c, 0x0d, 0x66, 0xd6, 0x73, 0x58,
     0x5c, 0xb4, 0x0a, 0x4d, 0xc2, 0x3b, 0xd2, 0xb7, 0xe2, 0xac, 0x33, 0xdb, 0x60, 0x27, 0xbd,
     0x56, 0x43, 0x24, 0x04, 0x02, 0x8d, 0x7d, 0x7f, 0xf6, 0xb5, 0xf4, 0xfd, 0xdd, 0x5b, 0xec,
     0x79, 0xc4, 0x22, 0x1f, 0xa1, 0x88, 0x54, 0xe7, 0x19, 0x98, 0x94, 0x7e, 0x31, 0xa3, 0x29,
     0xe3, 0x5a, 0xcb, 0x6a, 0xb0, 0xcf, 0x6d, 0x93, 0x6c, 0x7a, 0x08, 0xa9, 0x3c, 0x1c, 0xd0,
     0x63, 0x50, 0xc6, 0x85, 0x38, 0xc1, 0x41, 0x49, 0xab, 0x61, 0x52, 0x2a, 0x9f, 0xd9, 0x18,
     0x1a, 0x57, 0x46, 0x2b, 0x69, 0xda, 0xfa, 0xff, 0x0f, 0x15, 0x96, 0x3a, 0x8a, 0xfe, 0x9e,
     0x0c},
    {0x11, 0xa2, 0x9a, 0xc3, 0x94, 0xa0, 0x51, 0x01, 0x5b, 0xf7, 0xd1, 0x30, 0xee, 0x1f, 0x06,
     0xd5, 0x77, 0x67, 0xd3, 0xc1, 0x6e, 0xe7, 0x6a, 0x1a, 0xa4, 0x8e, 0x9f, 0x65, 0x66, 0xd6,
     0x0c, 0x2d, 0xc6, 0xe4, 0x69, 0xb7, 0x56, 0x5a, 0x57, 0x60, 0xfc, 0x79, 0x1e, 0xe1, 0x16,
     0x52, 0xf0, 0x07, 0xd0, 0xcd, 0xca, 0x78, 0xc9, 0x8b, 0xb3, 0x88, 0x27, 0xf6, 0xe0, 0xc0,
     0x84, 0xcf, 0x2f, 0xa3, 0x04, 0x00, 0x80, 0x40, 0xa7, 0xfa, 0x75, 0x9d, 0x4b, 0x89, 0x46,
     0x22, 0x28, 0x37, 0x34, 0x13, 0xff, 0x20, 0xb4, 0xda, 0x08, 0x26, 0x6c, 0x8f, 0xf2, 0x5d,
     0x7b, 0x73, 0x5c, 0x4c, 0x90, 0x71, 0x41, 0x8a, 0x9e, 0xbb, 0x12, 0xe8, 0x55, 0x6d, 0x2a,
     0x25, 0x4a, 0xaf, 0xbd, 0x95, 0x19, 0xa5, 0x31, 0xba, 0xad, 0xd9, 0xc5, 0xa6, 0x6b, 0x83,
     0xc4, 0xb6, 0xa9, 0xcc, 0xf9, 0xa1, 0xb1, 0x7a, 0xdc, 0xc7, 0xdb, 0x2e, 0x7e, 0x7f, 0x8d,
     0x4e, 0x62, 0x0f, 0x03, 0x39, 0xfd, 0xb8, 0xd4, 0x18, 0xc2, 0xec, 0x61, 0x02, 0x53, 0x1c,
     0x3b, 0x7d, 0xbc, 0x1d, 0x59, 0xf5, 0x8c, 0x98, 0xf1, 0x6f, 0x93, 0x85, 0xf8, 0x2c, 0x74,
     0xd8, 0x5e, 0x4d, 0x97, 0xab, 0x87, 0x82, 0x0a, 0x21, 0x42, 0x5f, 0x0d, 0x58, 0x33, 0x44,
     0x3a, 0xdd, 0xe9, 0xfb, 0x50, 0x47, 0xc8, 0xd7, 0x81, 0x9b, 0xe5, 0x1b, 0x17, 0x54, 0x86,
     0x2b, 0xef, 0xf4, 0x29, 0x32, 0x0e, 0x7c, 0x23, 0x15, 0xeb, 0xe6, 0x3c, 0x35, 0xe2, 0x96,
     0x68, 0x3f, 0x0b, 0x43, 0xce, 0xde, 0x9c, 0xbe, 0x4f, 0x45, 0x72, 0x76, 0xb5, 0x10, 0xe3,
     0xdf, 0x92, 0xd2, 0xa8, 0x48, 0x91, 0xb9, 0xac, 0xbf, 0x49, 0xb2, 0x99, 0x64, 0x70, 0xea,
     0xf3, 0x3e, 0x63, 0x14, 0xae, 0xed, 0xaa, 0x24, 0xfe, 0x3d, 0xcb, 0xb0, 0x09, 0x38, 0x36,
     0x05},
    {0xc4, 0xf0, 0x28, 0x49, 0x55, 0x4a, 0xf5, 0xfd, 0x75, 0xaf, 0x20, 0x69, 0xc8, 0x43, 0x86,
     0x6b, 0xc9, 0xa8, 0xc6, 0x54, 0x4c, 0xdd, 0x02, 0x5b, 0xe8, 0x9b, 0x59, 0x77, 0x34, 0xd7,
     0xc0, 0x51, 0x5f, 0xf3, 0x7e, 0xd4, 0xf1, 0x90, 0x81, 0xce, 0x19, 0x8a, 0x78, 0x33, 0xcd,
     0x97, 0x8c, 0xd6, 0x6a, 0x4b, 0x8f, 0xa4, 0x80, 0xdc, 0x1a, 0x17, 0x14, 0xc5, 0x07, 0x87,
     0x66, 0xad, 0x9d, 0x85, 0xb2, 0xf8, 0x8d, 0x98, 0xdf, 0x3e, 0x1f, 0x3f, 0x64, 0x58, 0x40,
     0xac, 0x6c, 0x5c, 0x08, 0x5d, 0x53, 0xba, 0xff, 0xd2, 0xa9, 0x2c, 0x25, 0xab, 0xe4, 0x32,
     0x38, 0x9a, 0xf9, 0xcb, 0xc2, 0x91, 0x67, 0xd0, 0xe3, 0x22, 0x29, 0x2d, 0x92, 0x48, 0xb4,
     0x0e, 0x99, 0x05, 0xa3, 0x6f, 0x0a, 0x15, 0xef, 0xd5, 0x10, 0x4f, 0xd8, 0xf6, 0x00, 0xe6,
     0x46, 0x2b, 0x31, 0x57, 0x83, 0x94, 0xae, 0x03, 0xeb, 0x8e, 0x13, 0x24, 0xa1, 0x1e, 0x5e,
     0xd1, 0x26, 0xd9, 0xa7, 0xca, 0x36, 0x6e, 0x71, 0x37, 0xee, 0xb1, 0xfa, 0x7c, 0x76, 0x06,
     0xb8, 0x23, 0xbe, 0x21, 0xbc, 0x9e, 0xc1, 0xda, 0x7a, 0x3b, 0x62, 0x27, 0x7b, 0xb0, 0xe5,
     0x63, 0x18, 0x82, 0x7f, 0x0f, 0xed, 0xa0, 0x2a, 0x9c, 0xbf, 0x11, 0xbd, 0xe0, 0x88, 0x0d,
     0x3a, 0x79, 0x52, 0x56, 0xf7, 0xb6, 0xd3, 0x09, 0x16, 0x1b, 0x70, 0xb3, 0x42, 0x60, 0x2f,
     0x1c, 0xa2, 0x9f, 0x72, 0x12, 0x45, 0x47, 0xbb, 0xe1, 0x0b, 0x01, 0x8b, 0x1d, 0xde, 0xec,
     0x0c, 0x4e, 0xe9, 0xcf, 0xcc, 0x95, 0x74, 0xf4, 0xa5, 0x93, 0xc7, 0xdb, 0x4d, 0xfb, 0x35,
     0x65, 0xfe, 0xe7, 0x39, 0xb5, 0xea, 0x96, 0xc3, 0x04, 0x41, 0x44, 0x84, 0xfc, 0x6d, 0x30,
     0xe2, 0xf2, 0x68, 0xb7, 0x89, 0x7d, 0x73, 0x3d, 0xb9, 0x5a, 0x50, 0xa6, 0x3c, 0x61, 0xaa,
     0x2e},
    {0x1a, 0x59, 0x9c, 0xad, 0xc8, 0xe4, 0x11, 0x54, 0xed, 0x37, 0x0f, 0x3a, 0xe6, 0x5f, 0x3c,
     0x4b, 0xb8, 0x15, 0x89, 0xb1, 0xe8, 0xda, 0x69, 0x77, 0x91, 0x56, 0x8b, 0xdb, 0x06, 0x24,
     0xcf, 0x18, 0xf8, 0xb0, 0x87, 0xdf, 0x8c, 0x35, 0xcb, 0x86, 0x53, 0x9d, 0xa4, 0x66, 0x4a,
     0x7a, 0x71, 0x0a, 0x48, 0x38, 0xff, 0xdc, 0x83, 0x20, 0xce, 0x98, 0x32, 0xf6, 0xd7, 0xaf,
     0x70, 0x5e, 0x73, 0x8a, 0x14, 0x72, 0x1e, 0xc1, 0x29, 0x79, 0x07, 0x08, 0xe9, 0x43, 0x46,
     0xd0, 0x2f, 0xde, 0x2a, 0x4f, 0x3d, 0x2c, 0x50, 0xb3, 0x75, 0xfc, 0x0b, 0x64, 0xae, 0x31,
     0x7b, 0x61, 0xa5, 0x30, 0xa0, 0x93, 0xd2, 0xbe, 0xc2, 0x55, 0xba, 0x6c, 0xf3, 0x62, 0x68,
     0xfd, 0xac, 0x3b, 0x95, 0x49, 0x1f, 0x6b, 0xb4, 0x85, 0xf7, 0xa6, 0x03, 0xec, 0x6e, 0x9a,
     0x81, 0x09, 0x0c, 0x6a, 0xee, 0x9e, 0x4e, 0xf0, 0xab, 0x2d, 0x7e, 0xa1, 0xe1, 0xbb, 0xc9,
     0xbc, 0x41, 0xf2, 0xfa, 0x2e, 0x1b, 0xdd, 0x27, 0x34, 0xd3, 0x60, 0x04, 0xb5, 0x01, 0xd6,
     0x40, 0xf9, 0xd5, 0x02, 0x47, 0xd9, 0xd8, 0xe0, 0x8f, 0x2b, 0xfb, 0xb7, 0xc5, 0xeb, 0x57,
     0x16, 0xe5, 0x78, 0x8d, 0xf4, 0x00, 0xcd, 0x82, 0x39, 0xc6, 0x96, 0xbd, 0xbf, 0xe3, 0x36,
     0x45, 0x0e, 0x26, 0x1d, 0x63, 0xe7, 0x84, 0x3e, 0xb6, 0x9b, 0x22, 0xa3, 0xf5, 0x8e, 0x23,
     0x6d, 0xc3, 0x99, 0x7d, 0x90, 0x97, 0x10, 0x25, 0x80, 0xd4, 0x4c, 0xe2, 0x74, 0xcc, 0xb2,
     0x5c, 0x33, 0xc7, 0xea, 0x05, 0x12, 0x3f, 0x51, 0xa8, 0xfe, 0xf1, 0x1c, 0x42, 0xca, 0xd1,
     0x76, 0x28, 0x6f, 0x92, 0xa7, 0x67, 0xa9, 0x19, 0xa2, 0x44, 0x5b, 0xaa, 0xef, 0x58, 0x7f,
     0x21, 0xc0, 0x88, 0x65, 0xb9, 0x5d, 0x4d, 0x0d, 0x5a, 0xc4, 0x13, 0x52, 0x7c, 0x9f, 0x94,
     0x17},
    {0xc7, 0x2b, 0x82, 0x61, 0x5b, 0xd0, 0x96, 0x84, 0xd3, 0x4a, 0x70, 0xa1, 0x9b, 0x59, 0x33,
     0x9f, 0xc0, 0x20, 0x14, 0x53, 0x29, 0x17, 0xc5, 0x0b, 0xc9, 0x7b, 0x97, 0x02, 0x0d, 0x3a,
     0x1e, 0x7c, 0x3f, 0x6b, 0x52, 0xe8, 0x75, 0x3d, 0xf6, 0xe4, 0x0c, 0x8a, 0x4f, 0xc3, 0x5f,
     0x26, 0x65, 0x73, 0x31, 0x23, 0x28, 0x48, 0x74, 0xaa, 0xa7, 0x36, 0x09, 0xb1, 0xe2, 0x91,
     0x04, 0x51, 0x22, 0xfc, 0x08, 0xa6, 0x05, 0xa4, 0xf1, 0x12, 0x1c, 0x19, 0xeb, 0x40, 0x37,
     0xc2, 0xa0, 0x41, 0x1d, 0xd4, 0xdc, 0x07, 0x43, 0x8f, 0x47, 0xaf, 0xd1, 0x2e, 0x98, 0xab,
     0x01, 0xba, 0xf0, 0x66, 0x68, 0xac, 0xf9, 0xe7, 0x69, 0xb6, 0xcb, 0x8d, 0x78, 0x87, 0x15,
     0x03, 0xd5, 0xdf, 0xa3, 0x1a, 0x9d, 0x6a, 0xea, 0x2f, 0x94, 0x4e, 0x9e, 0x42, 0xd7, 0xb8,
     0x38, 0x92, 0xd8, 0xbb, 0xde, 0xdd, 0x9a, 0xbc, 0xb0, 0x4c, 0x79, 0xf4, 0x58, 0x3e, 0xe9,
     0x83, 0x81, 0xff, 0xe3, 0x55, 0xfd, 0x5d, 0xb2, 0xef, 0x9c, 0x6d, 0x54, 0x99, 0x60, 0xda,
     0x3b, 0xec, 0xfa, 0x11, 0xd6, 0xc4, 0x2a, 0xed, 0x4b, 0xae, 0x13, 0xbf, 0xb9, 0x06, 0x8b,
     0xe0, 0x1f, 0x7f, 0x5a, 0xad, 0x90, 0x39, 0x0f, 0xf3, 0xbd, 0x46, 0x6c, 0x2c, 0xf2, 0xf8,
     0xfe, 0xd9, 0xe6, 0x72, 0x0e, 0x89, 0xbe, 0x5e, 0xc6, 0xa8, 0xcf, 0xf5, 0x57, 0x7e, 0x8c,
     0xb7, 0xe1, 0x88, 0x7a, 0xc8, 0x1b, 0x18, 0xdb, 0x6f, 0x35, 0xd2, 0x16, 0x32, 0x64, 0x63,
     0xa5, 0x8e, 0xf7, 0xb4, 0x76, 0x95, 0x86, 0x7d, 0xe5, 0xa9, 0x5c, 0x85, 0x00, 0xc1, 0x93,
     0x4d, 0xfb, 0x30, 0xa2, 0xb5, 0x25, 0x34, 0x10, 0x77, 0x3c, 0x67, 0x71, 0x2d, 0x44, 0x45,
     0x56, 0x0a, 0x50, 0xb3, 0xcd, 0x62, 0x80, 0xce, 0x21, 0x49, 0x24, 0xca, 0xee, 0x27, 0x6e,
     0xcc},
    {0xa5, 0xb0, 0x6d, 0xb2, 0x51, 0x55, 0x1f, 0xbf, 0x3e, 0x8d, 0xdd, 0x19, 0x92, 0xea, 0x1b,
     0xbd, 0x32, 0x65, 0x29, 0xa4, 0x89, 0x67, 0xb1, 0x90, 0x68, 0x00, 0xda, 0x0d, 0xa6, 0x59,
     0x54, 0xf2, 0x10, 0x14, 0x2f, 0x45, 0xe0, 0x3b, 0x23, 0xfa, 0xd7, 0x50, 0xac, 0x93, 0xe6,
     0x43, 0x01, 0x0a, 0x5c, 0x78, 0x70, 0x98, 0x46, 0xa9, 0x7b, 0xf3, 0x95, 0x07, 0x2a, 0xd3,
     0x74, 0xb3, 0x3f, 0xa3, 0x60, 0x82, 0x39, 0x4e, 0x34, 0x48, 0xc0, 0x1c, 0xf6, 0xc2, 0x91,
     0x64, 0x4d, 0x3c, 0xf8, 0x9d, 0x35, 0x9a, 0x94, 0xe3, 0x7a, 0xf0, 0xf9, 0x6e, 0xb9, 0x12,
     0xb8, 0x04, 0x2d, 0x02, 0x28, 0x13, 0x85, 0x72, 0x80, 0x87, 0xdb, 0x2b, 0xf1, 0x4f, 0x26,
     0xa2, 0xe1, 0x49, 0x7e, 0x9c, 0xcc, 0xa7, 0xb6, 0xa0, 0xd0, 0x9b, 0x36, 0x77, 0xad, 0x8b,
     0x6b, 0x4a, 0x03, 0x1d, 0x05, 0x8a, 0x06, 0x4b, 0xaf, 0xe5, 0x31, 0xb5, 0xd4, 0xc6, 0x0c,
     0x66, 0xba, 0x83, 0xfd, 0x09, 0x0f, 0xae, 0x71, 0xb7, 0x6f, 0xdc, 0x41, 0xe8, 0x17, 0x8e,
     0x40, 0x7f, 0x62, 0x30, 0xff, 0xa8, 0x84, 0x25, 0xfb, 0x16, 0xce, 0x37, 0x44, 0xab, 0x99,
     0x1e, 0xeb, 0x18, 0x3a, 0x47, 0xf7, 0x5f, 0x81, 0xcf, 0xed, 0x58, 0x2c, 0x6c, 0xfe, 0x9e,
     0x57, 0x53, 0x97, 0x20, 0xca, 0x79, 0x1a, 0x5a, 0x88, 0xf5, 0x69, 0x9f, 0xe7, 0xd9, 0x0e,
     0xbe, 0x42, 0xdf, 0x56, 0xe4, 0x4c, 0x22, 0xaa, 0x73, 0x0b, 0x15, 0xc5, 0xee, 0xfc, 0xc7,
     0xd6, 0xcb, 0xcd, 0x8c, 0xe2, 0x76, 0x21, 0xe9, 0xd1, 0xec, 0xc8, 0x7d, 0xd8, 0x8f, 0x61,
     0x7c, 0x2e, 0xbc, 0xde, 0xb4, 0x75, 0xd2, 0xc4, 0x63, 0x3d, 0xa1, 0x5e, 0x5d, 0x6a, 0x08,
     0x24, 0xc9, 0x27, 0xbb, 0xef, 0x33, 0x86, 0x5b, 0xd5, 0x38, 0x52, 0x11, 0xf4, 0xc3, 0x96,
     0xc1},
    {0x34, 0x5a, 0xdb, 0x2c, 0x59, 0x57, 0x12, 0x2b, 0x30, 0xc2, 0xa0, 0x92, 0xbf, 0xed, 0xbc,
     0x45, 0xde, 0x27, 0x9b, 0x96, 0xd3, 0xe6, 0xc5, 0xeb, 0xd8, 0x24, 0x4b, 0xa4, 0x21, 0xcc,
     0xa8, 0xd6, 0xce, 0x3c, 0xba, 0xb1, 0x09, 0xe0, 0xd7, 0x32, 0x66, 0x4a, 0x83, 0x1d, 0x19,
     0xca, 0x89, 0x67, 0x0f, 0x42, 0x07, 0x71, 0xe9, 0xbb, 0x44, 0x5e, 0x85, 0x17, 0xc4, 0xae,
     0x9c, 0x3f, 0x6b, 0x78, 0xe7, 0x6d, 0x02, 0xa7, 0xfe, 0x33, 0xe3, 0xd9, 0x0a, 0x7d, 0xea,
     0xf1, 0x18, 0x87, 0x7b, 0x62, 0x03, 0x79, 0x52, 0x23, 0x00, 0x3e, 0x25, 0xb9, 0xdd, 0x16,
     0x68, 0x3b, 0x1f, 0x90, 0xa6, 0x2a, 0xc6, 0x29, 0x91, 0x8a, 0x9d, 0xef, 0x1e, 0x84, 0x76,
     0xee, 0x4f, 0x39, 0xfb, 0x11, 0x1b, 0x0b, 0x93, 0xad, 0x49, 0xb7, 0x05, 0xe1, 0x4d, 0xcb,
     0xe8, 0x38, 0xd0, 0x55, 0xf2, 0xf7, 0x0d, 0x8b, 0x65, 0xcd, 0xfa, 0xd4, 0x9e, 0xc9, 0x81,
     0x4e, 0x14, 0xc8, 0x26, 0xb6, 0xf9, 0xaa, 0xf5, 0x80, 0xf8, 0x6a, 0x98, 0xab, 0x58, 0xf3,
     0xb8, 0x8e, 0xb5, 0x97, 0x43, 0x72, 0xa2, 0xda, 0x64, 0xc1, 0x40, 0x5c, 0x13, 0xb0, 0xe5,
     0xbd, 0x08, 0x9f, 0x1c, 0x7e, 0x8f, 0x06, 0xbe, 0x6e, 0x50, 0x1a, 0x2f, 0x37, 0xa1, 0xfc,
     0x10, 0x2e, 0x70, 0x53, 0x04, 0x20, 0x63, 0x48, 0xe2, 0xfd, 0x6f, 0x7a, 0x75, 0x61, 0xb3,
     0x35, 0x3a, 0xcf, 0x5b, 0x88, 0x82, 0x51, 0xd2, 0x47, 0xa5, 0xa9, 0x74, 0x6c, 0x31, 0x94,
     0x7c, 0x9a, 0xc0, 0xec, 0x15, 0x0e, 0x28, 0x01, 0x2d, 0xc3, 0xf0, 0xb4, 0xe4, 0x8d, 0xdc,
     0xac, 0x3d, 0x5f, 0x86, 0xc7, 0x95, 0x22, 0xf4, 0xb2, 0xa3, 0x54, 0x46, 0xd1, 0x77, 0x8c,
     0x0c, 0xff, 0xaf, 0x56, 0x5d, 0x36, 0x69, 0x7f, 0x99, 0x4c, 0xd5, 0x60, 0x73, 0xdf, 0x41,
     0xf6},
    {0x04, 0xda, 0x79, 0x63, 0x1e, 0xbd, 0xea, 0xe3, 0x0b, 0x65, 0x25, 0x01, 0xcd, 0xa9, 0x92,
     0xed, 0x18, 0x75, 0x57, 0x30, 0x89, 0x03, 0x09, 0x6a, 0xdc, 0xc7, 0x98, 0xa4, 0x50, 0x91,
     0x1f, 0xb1, 0x0c, 0x77, 0x85, 0x66, 0xca, 0x12, 0x1c, 0x67, 0xc2, 0xe0, 0x17, 0x83, 0x59,
     0x9d, 0xd5, 0x22, 0x82, 0x56, 0xa8, 0x9f, 0xc6, 0x60, 0x48, 0xb3, 0x11, 0xfc, 0xa3, 0x28,
     0xfb, 0x06, 0xdd, 0x5d, 0xba, 0x29, 0x7a, 0x4f, 0xe8, 0xfe, 0xe9, 0x10, 0xcb, 0xf3, 0x93,
     0x7b, 0x6c, 0x69, 0x54, 0xe7, 0x44, 0xa2, 0x84, 0x1d, 0x8d, 0xce, 0xff, 0xfa, 0x1a, 0x87,
     0x90, 0x74, 0xa1, 0xf8, 0x14, 0xaa, 0xbc, 0xc0, 0xcf, 0x31, 0xb4, 0xd9, 0xbf, 0xd8, 0x5e,
     0x26, 0x2d, 0xd0, 0xe4, 0x3f, 0x19, 0xd6, 0x8c, 0x2f, 0xab, 0x39, 0x58, 0x72, 0x6e, 0xdf,
     0x3b, 0xe6, 0x3c, 0xb6, 0x62, 0x88, 0xde, 0x40, 0xb2, 0x8f, 0x9b, 0x7c, 0x95, 0x43, 0xd1,
     0x9e, 0xac, 0x9c, 0xd4, 0x23, 0xe1, 0x0e, 0x4b, 0x53, 0x33, 0x46, 0x20, 0x13, 0x34, 0x1b,
     0x97, 0xf7, 0xf1, 0xc3, 0x61, 0x4a, 0x6f, 0x5a, 0x21, 0x7f, 0x70, 0x2e, 0x55, 0x41, 0x05,
     0xc5, 0xd7, 0x76, 0xe5, 0x27, 0x15, 0xec, 0x42, 0x5c, 0x4d, 0x78, 0x35, 0x8b, 0xef, 0xd2,
     0xee, 0xb5, 0xbe, 0xae, 0x02, 0x3a, 0xd3, 0x5f, 0xc4, 0x24, 0xf0, 0xf9, 0x51, 0x4e, 0xeb,
     0x00, 0x0f, 0xfd, 0xaf, 0x3e, 0xc1, 0x9a, 0x52, 0x86, 0x81, 0x80, 0x7e, 0xf6, 0x2b, 0xcc,
     0xb9, 0x7d, 0x68, 0xf2, 0xad, 0x99, 0xa7, 0x07, 0x2c, 0x73, 0x38, 0xb0, 0x6b, 0xb7, 0x8e,
     0x71, 0xa0, 0xf4, 0x3d, 0xa6, 0x0d, 0x37, 0xdb, 0x0a, 0x47, 0x36, 0x16, 0x96, 0x6d, 0x32,
     0x2a, 0x5b, 0xe2, 0x45, 0x94, 0xf5, 0xa5, 0x4c, 0xc8, 0x8a, 0x49, 0x64, 0xbb, 0x08, 0xc9,
     0xb8}
};

static void rotate_right(uint8_t* data, size_t n_bytes, size_t n_bits) {
    /*
    def rotate_right(data, n_bytes, n_bits):
        prior = data[n_bytes - 1]
        for i in range(n_bytes):
            prior, data[i] = data[i], (data[i] >> n_bits) | ((prior & ((1 << n_bits) - 1)) << (8 - n_bits))
    */
    uint8_t prior = data[n_bytes - 1];
    for (size_t i = 0; i < n_bytes; i++) {
        uint8_t tmp = prior;
        prior = data[i];
        data[i] = (data[i] >> n_bits) | ((tmp & ((1 << n_bits) - 1)) << (8 - n_bits));
    }
}

/*
https://sega.bsnk.me/allnet/amusement_ic/

spad0 and out should be arrays of length FELICA_DATA_BLOCK_SIZE (ie. 16)
*/
void aic_access_code_decrypt(const uint8_t* spad0, uint8_t* out) {
    /*
    out = bytearray(S_BOX_INV[8][i] for i in spad)

    count = (out[15] >> 4) + 7
    table = out[15] + 5 * count

    for _ in range(count):
        table -= 5
        rotate_right(out, 15, 5)
        for i in range(15):
            out[i] = S_BOX_INV[table % 8][out[i]]

    return out
    */

    for (size_t i = 0; i < 16; i++) {
        out[i] = S_BOX_INV[8][spad0[i]];
    }

    uint8_t count = (out[15] >> 4) + 7;
    uint8_t table = out[15] + 5 * count;

    while (count--) {
        table -= 5;

        rotate_right(out, 15, 5);

        for (size_t i = 0; i < 15; i++) {
            out[i] = S_BOX_INV[table % 8][out[i]];
        }
    }
}
