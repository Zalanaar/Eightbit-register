#include <systemc.h>

SC_MODULE(eightbit_register) {

	sc_in_clk clock;
	sc_in<bool> reset;
	sc_in<sc_uint<8> > register_in;
	sc_out<sc_uint<8> > register_out;
	sc_in<bool> ena;
	sc_out<bool> parity;
	sc_in<bool> cin;
	sc_out<bool> cout;


	sc_signal<sc_uint<8> > myregister;


	void register_store();
	void calculate_parity();
	void data_out_method();


	SC_CTOR(eightbit_register) :
		clock("clock"),
		reset("reset"),
		register_in("register_in"),
		register_out("register_out"),
		parity("parity"),
		ena("ena"),
		cout("cout"),
		cin("cin")
	{
		cout << "Executing new" << endl;

		SC_THREAD(register_store, clock.pos());
		async_reset_signal_is(reset, true);
		SC_METHOD(data_out_method);
		sensitive << myregister;
		SC_METHOD(calculate_parity);
		sensitive << myregister;
	}

};