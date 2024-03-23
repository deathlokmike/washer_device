void start {
  socket = websocket 
  while socket:
    if socket.start:
      flag_start = true
}


Core 0:
{
  http_client
  ov7670
  if flag_start:
    ov7670 -> photo 
    photo -> client
    client -> get (photo)
    wait_time (async)
    response =  true / false
    if response == false: 
      put stop_machine(true) to message_queue
    else
      if stop_machine is true:
        put stop_machine(false) to message_queue
      else
        pass
}

Core 1:
{
  class Sensor()
  {
    front US
    right US
  }

  class Algorithm (dist_front, dist_right){
    class wheel;
    class steering;
    dist_front, dist_right -> speed, angle
    if not stop_machine:
      wheel.move(speed)
      steering.turn(angle)
  }
}