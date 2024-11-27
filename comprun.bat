@echo off
g++ ./main.cpp ./Actuator/Actuator.cpp ./Actuator/Chiller/Chiller.cpp ./Actuator/FCU/FCU.cpp ./Actuator/Pumps/Pumps.cpp ./Actuator/Tower/Tower.cpp ./Circuits/Circuits.cpp ./Circuits/ChilledWater/ChilledWater.cpp ./Circuits/CondensedWater/CondensedWater.cpp ./Circuits/Recirculating/Recirculating.cpp ./Place/Place.cpp ./Place/AulasI/AulasI.cpp ./Place/AulasII/AulasII.cpp ./Place/Library/Library.cpp -o output

output.exe