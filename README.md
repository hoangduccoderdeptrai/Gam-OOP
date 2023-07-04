# Gam-OOP
Overlord là một seri anime thể loại chuyển sinh, tại đây nhân vật chính là Momonga phiêu lưu vào 
thế giới thần thoại đầy rẫy quái vật. Để làm nhiệm vụ nguy hiểm, như tiêu diệt boss, con người ở đây 
tạo ra Guild, một Guild sẽ bao gồm n thành viên thực hiện chung một nhiệm vụ nào đó, mỗi thành 
viên có tên và các chỉ số HP, ATK và DEF. 
  • HP là chỉ số sinh mệnh, nếu HP <=0 thì coi như đã chết, không còn khả năng ATK. 
  • ATK là chỉ số tấn công, DEF là chỉ số phòng thủ, mỗi lượt đánh sẽ gây sát thương (tức là trừ 
vào HP của đối phương) một lượng là (ATK bản thân – DEF đối phương), nếu DEF của đối 
phương cao hơn thì coi như sát thương là 0. 
Mỗi thành viên trong Guild có thể là: 
  • Nhân loại (có thêm thuộc tính job  class): bao gồm Human (loại  1)  và  Elf (loại  2). Người 
không có khả năng gì thêm, còn Elf được + 50% DEF dựa trên DEF nhập vào. 
  • Bán nhân (có thêm thuộc tính racial  class): bao gồm Orc (loại  3)  và  Golbin  (loại  4).  Orc 
được +50% HP dựa trên HP nhập vào, Golbin được + 10% ATK dựa trên ATK nhập vào. 
  • Dị hình: bao gồm Vampire (loại 5) và Devil (loại 6), Vampire được +10% HP / mỗi thành 
viên Guild là nhân loại, Devil được +10% ATK và +10% DEF / mỗi Devil trong Guild. 
Sau khi nhập các thông tin cho Guild, Giả sử Guild đi đánh Boss, hãy tính khả năng chiến thắng. Biết 
rằng 2 bên sẽ đánh nhau theo lượt, và bên Guild sẽ tấn công trước, tất cả các thành viên trong Guild 
sẽ lần lượt đánh vào Boss theo thứ tự trong đội hình, sau đó Boss sẽ tấn công vào thành viên ít máu 
nhất.
