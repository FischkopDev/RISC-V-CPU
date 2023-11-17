package de.home_skrobanek.risc.parser;

public enum Instruction {

    //ALU instructions
    NOP("0"),
    ADD("01"),
    ADDI("02"),
    SUB("03"),
    SUBI("04"),
    MULT("05"),
    MULTI("06"),
    DIV("07"),
    DIVI("08"),

    //Logical instruction
    JMP("10"),
    BEQ("11"),
    BNEQ("12"),
    PRNT("13"),
    RST("14"),
    READ("15");

    private String inValue;
    Instruction(String value){
        this.inValue = value;
    }

    public boolean isValid(Instruction instruction, String value){
        return instruction.toString().equalsIgnoreCase(value);
    }

    public String getValue(){
        return inValue;
    }

}
