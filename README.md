# CncApiNetFramework
EdingCncApi wrapper (C++/CLI .Net Framework 4.0)

# Sidenote
The CncApiNetFramework C ++ / CLI wrapper is not compatible with other .net runtimes such as mono. At the moment I am working on a new cncapi wrapper that is written entirely in C # (netstandard 2.0).
The current wrapper therefore has less priority. I will upload new versions of the cncapi released by edingcnc to Nuget.


# TODO
Adjust setters of all properties by setting the InternalCncMethods :: SetPropertyIfUnlocked (PT_S SOURCE, PT_S * DESTINATION, bool IS_LOCEKD).
Some of the Cncserver's variables are read-only pointers.

property sample:

current setters:

	public ref class CncBasicInterpreterStatus : public Managedstruct<CNC_BASIC_INTERPRETER_STATUS>
	{
		//.....
  		property CncCartBool^ axesPresent
  		{
			CncCartBool^get()
			{
				Temp_axesPresent->ValuePointertype = &ValuePointertype->axesPresent;
				return Temp_axesPresent;
			}
		
			void set(CncCartBool^ Value)
			{
				ValuePointertype->axesPresent =Temp_axesPresent->ValuePointertype[0];
			}
  		}
	//.....
	}


new setters:

	public ref class CncBasicInterpreterStatus : public Managedstruct<CNC_BASIC_INTERPRETER_STATUS>
	{
		//.....
  		property CncCartBool^ axesPresent
  		{
			CncCartBool^get()
			{
				Temp_axesPresent->ValuePointertype = &ValuePointertype->axesPresent;
				return Temp_axesPresent;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->axesPresent, LockOverrideDataInPointer);
			}
  		}
	//.....
	}








