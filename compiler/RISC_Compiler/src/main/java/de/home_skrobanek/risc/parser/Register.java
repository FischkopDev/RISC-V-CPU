package de.home_skrobanek.risc.parser;

public enum Register {

    ZERO("00"),
    RA("01"),
    SP("02"),
    GP("03"),
    TP("04"),
    T0("05"),
    T1("06"),
    T2("07"),
    S0("08"),
    S1("09"),
    S2("0A");

    private String value;

    Register(String value){
        this.value = value;
    }

    public String getValue(){
        return value;
    }
}
