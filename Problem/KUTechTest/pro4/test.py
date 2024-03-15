def find_min_rounds(m, t, s, n, passengers):
  """
  ฟังก์ชั่นหาจำนวนรอบการขนส่งผู้โดยสารน้อยที่สุด

  Args:
    m: จำนวนที่นั่งรถไฟฟ้า
    t: ระยะเวลาที่รถไฟฟ้าเข้าชานชาลา
    s: จำนวนสถานี
    n: จำนวนผู้โดยสาร
    passengers: รายการข้อมูลผู้โดยสาร [ชานชาลา, สถานีปลายทาง, เวลารอ]

  Returns:
    tuple: (จำนวนรอบ, ระยะเวลา)
  """

  # เรียงลำดับผู้โดยสารตามเวลาที่ขึ้นรถ
  passengers.sort(key=lambda p: p[2])

  # จำลองเวลา
  time = 0

  # จำนวนรอบ
  rounds = 0

  # ผู้โดยสารที่รออยู่บนชานชาลา
  waiting_passengers = []

  # สถานีปัจจุบัน
  current_station = 1

  while passengers or waiting_passengers:
    # เพิ่มผู้โดยสารที่มาถึงชานชาลาในเวลานี้
    for passenger in passengers:
      if passenger[2] <= time:
        waiting_passengers.append(passenger)

    # ขนส่งผู้โดยสาร
    if waiting_passengers:
      # เรียงลำดับผู้โดยสารตามสถานีปลายทาง
      waiting_passengers.sort(key=lambda p: p[1])

      # ขนส่งผู้โดยสารจนเต็ม หรือ ถึงสถานีปลายทาง
      while waiting_passengers and (len(waiting_passengers) <= m or current_station == waiting_passengers[0][1]):
        passenger = waiting_passengers.pop(0)
        time += t
        current_station = passenger[1]

      # เพิ่มจำนวนรอบ
      if current_station == s:
        rounds += 1
        current_station = 1

    # รอจนถึงเวลาเข้าชานชาลาถัดไป
    time += max(0, t - (time % t))

  # เวลาที่ใช้
  total_time = time

  return rounds, total_time

# รับค่าอินพุต
m, t, s, n = map(int, input().split())
passengers = [list(map(int, input().split())) for _ in range(n)]

# หาจำนวนรอบและเวลา
rounds, total_time = find_min_rounds(m, t, s, n, passengers)

# พิมพ์ผลลัพธ์
print(rounds)
print(total_time)
