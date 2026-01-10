 

%looking for Static Thrust (Hovering Dorne) based on the amount of current
%draw from the ESCs. 

% use Thrust = (Thrust Coef.) * (Air density) * (rotational speed)^2 *
% (Diameter)^4 

%assume Coefficient of thrust of 0.03, typical of small hobby drones. 

% Rotations per Minute = Kv * Voltage 
PulseMin = 1000; 
PulseMax = 2000;
KvValue = 2750; 
PropDiameter = 0.13; 
ThrustCoef = 0.025; 
AirDensity = 1.225;



 

%% calculate theoretical thrust
%MotorThrust = (0.03) * (1.225) * ((RotationsPerSecond)^2) * ((PropDiameter)^4); 
%DroneThrust = MotorThrust  * 4; 


%% map chaning pulse values to changing thrust and find current draw 
motorEffficiency = 0.61; 
Pulse = 1000:50:2000; 
MotorThrust = zeros(size(Pulse)); 
propArea = pi * (PropDiameter / 2)^2; 

for i = 1:length(Pulse)
    VoltageMotors = (Pulse(i) - PulseMin)/(PulseMax - PulseMin) * 11.1; 
    RotationsPerSecond = (KvValue * VoltageMotors)/60; 
    MotorThrust(i) = ThrustCoef * AirDensity * (RotationsPerSecond^2) * (PropDiameter^4);
    
    inducedVelocity = sqrt(MotorThrust(i) / (2 * AirDensity * propArea )); 
    MechanicalPower = MotorThrust(i) * inducedVelocity; 
    ElectricalPower = MechanicalPower / motorEffficiency;
    CurrentDraw(i) = ElectricalPower/VoltageMotors; 

end

DroneThrust = MotorThrust * 4; 



%Using I = P/V and https://orbray.com/en/product/dccorelessmotor/brushless_ca_bms12-15.html
% P = Torque * induced Velocity ( momentum Theory) 
% v = sqrt(Toruqe / 2 * rho * Area) 



%% plot 
figure;
subplot(2,1,1);
plot(Pulse, DroneThrust, 'r-o');
xlabel('Pulse in Microseconds')
ylabel('Thrust in Newtons');
grid on; 
title('Motor Thrust vs Pulse Value'); 

subplot(2,1,2);
plot(Pulse, CurrentDraw, 'b-o');
xlabel("Pulse in Microseconds");
ylabel("Current Draw in Amps"); 
grid on; 
title("Current Draw vs Pulse Value"); 

%% slider that adjusts bar graphs 
%using https://www.mathworks.com/matlabcentral/answers/737092-slider-which-controls-a-bar-plot

fig = uifigure;
barSlider = uislider(fig, 'Position', [50 50 150 3]); 
barSlider.Limits = [1000 2000]; 

ax = uiaxes(fig, 'Position',[20 100 500 300] ); 
ylabel(ax, 'amount');
ax.XTickLabel = {'Drone Thrust(N)',  'Current Draw (Amps)'};
ax.YLim = [0 15]; 


barGraph = bar(ax, [0 0]); 

barSlider.ValueChangedFcn = @(sld,event) updateValues(sld.Value, barGraph); 

function updateValues(pulseValue, barGraph)
    PulseMin = 1000; 
    PulseMax = 2000;
    KvValue = 2750; 
    PropDiameter = 0.13; 
    ThrustCoef = 0.025; 
    AirDensity = 1.225;
    motorEffficiency = 0.61;
     
    propArea = pi * (PropDiameter / 2)^2;

    VoltageMotors = (pulseValue - PulseMin)/(PulseMax - PulseMin) * 11.1; 
    RotationsPerSecond = (KvValue * VoltageMotors)/60; 
    MotorThrust = ThrustCoef * AirDensity * (RotationsPerSecond^2) * (PropDiameter^4);
    DroneThrust = MotorThrust * 4;

    inducedVelocity = sqrt(MotorThrust / (2 * AirDensity * propArea )); 
    MechanicalPower = MotorThrust * inducedVelocity; 
    ElectricalPower = MechanicalPower / motorEffficiency;
    CurrentDraw = ElectricalPower/VoltageMotors;

    barGraph.YData = [DroneThrust CurrentDraw]; 

    drawnow

end
