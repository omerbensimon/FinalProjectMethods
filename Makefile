CXX = g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Controls/Label.o Controls/Button.o Controls/CheckList.o Controls/ComboBox.o Controls/MessageBoxPanel.o Controls/NumericBox.o Controls/Panel.o Controls/RadioBox.o Controls/TextBox.o Painters/DoubleBorderPainter.o Painters/SingelBorderPainter.o  

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe


