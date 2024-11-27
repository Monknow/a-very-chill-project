@echo off
g++ general.cpp ..\Actuator\Actuator.cpp ..\Actuator\Chiller\Chiller.cpp ..\Actuator\FCU\FCU.cpp ..\Actuator\Pumps\Pumps.cpp ..\Actuator\Tower\Tower.cpp ..\Circuits\Circuits.cpp ..\Circuits\ChilledWater\ChilledWater.cpp ..\Circuits\CondensedWater\CondensedWater.cpp ..\Circuits\Recirculating\Recirculating.cpp ..\Place\Place.cpp ..\Place\Classroom\Classroom.cpp ..\Place\Library\Library.cpp -o tests

tests.exe