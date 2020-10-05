bridge_length = 2
weight = 10
truck_weights = [7, 4, 5, 6]
bridge = [0]
onTime = [-1*bridge_length]

time = 0
while(True) :
    #print("bridge : {0}\ntruck_weights: {1}".format(bridge, truck_weights))
    if not bridge and not truck_weights : break

    if time - onTime[0] == bridge_length :
        onTime.pop(0)
        bridge.pop(0)
        
    if truck_weights :
        if sum(bridge) + truck_weights[0] <= weight :
            bridge.append(truck_weights.pop(0))
            onTime.append(time)
    
    time += 1

print(time)

    
    

    