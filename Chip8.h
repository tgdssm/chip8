//
// Created by Thalisson Melo on 07/09/23.
//

#include <cstdint>
#include <random>

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;
const unsigned int REGISTERS = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int STACK = 16;
const unsigned int KEYS = 16;

class Chip8 {
public:
    Chip8();

    void Cycle();

    void LoadROM(const char *filename);

    uint8_t registers[REGISTERS]{};
    uint8_t memory[MEMORY_SIZE]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[STACK]{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[KEYS]{};
    uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{};
    uint16_t opcode{};

    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;

private:
    typedef void (Chip8::*Chip8Function)();

    Chip8Function table[0xF + 1];
    Chip8Function table0[0xE + 1];
    Chip8Function table8[0xE + 1];
    Chip8Function tableE[0xE + 1];
    Chip8Function tableF[0x65 + 1];

    void Table0();

    void Table8();

    void TableE();

    void TableF();

    void OP_NULL();

    // CLS
    void OP_00E0();

    // RET
    void OP_00EE();

    // SYS addr
    void OP_0nnn();

    // JP addr
    void OP_1nnn();

    // CALL addr
    void OP_2nnn();

    // SE Vx, byte
    void OP_3xkk();

    // SNE Vx,byte
    void OP_4xkk();

    // SE Vx, Vy
    void OP_5xy0();

    // LD Vx, byte
    void OP_6xkk();

    // ADD Vx, byte
    void OP_7xkk();

    // LC Vx, Vy
    void OP_8xy0();

    // OR Vx, Vy
    void OP_8xy1();

    // AND Vx, Vy
    void OP_8xy2();

    // XOR Vx, Vy
    void OP_8xy3();

    // ADD Vx, Vy
    void OP_8xy4();

    // SUB Vx, Vy
    void OP_8xy5();

    // SHR Vx, {, Vy}
    void OP_8xy6();

    // SUBN Vx, Vy
    void OP_8xy7();

    // SHL Vx {, Vy}
    void OP_8xyE();

    // SNE Vx, Vy
    void OP_9xy0();

    // LD I, addr
    void OP_Annn();

    // JP V0, addr
    void OP_Bnnn();

    // RND Vx, byte
    void OP_Cxkk();

    // DRW Vx, Vy, nibble
    void OP_Dxyn();

    // SKP Vx
    void OP_Ex9E();

    // SKNP Vx
    void OP_ExA1();

    // LD Vx, DT
    void OP_Fx07();

    // LD Vx, K
    void OP_Fx0A();

    // LD DT, Vx
    void OP_Fx15();

    // LD ST, Vx
    void OP_Fx18();

    // ADD I, Vx
    void OP_Fx1E();

    // LD F, Vx
    void OP_Fx29();

    // LD B, Vx
    void OP_Fx33();

    // LD [I], Vx
    void OP_Fx55();

    // LD Vx, [I]
    void OP_Fx65();

};


#endif //CHIP8_CHIP8_H
