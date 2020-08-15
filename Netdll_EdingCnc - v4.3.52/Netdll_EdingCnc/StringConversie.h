#pragma once
#include <msclr\marshal_cppstd.h>//is voor sdt:string naar system:string
#include <iostream>
#pragma warning( disable : 4996 )

using namespace System;
//using namespace std;

namespace OosterhofDesign
{
	public ref class  StringConversie
	{
	public:
		//---------only for debuggin to analize the size of the onderlying chars
		static int Log_SetCharSize = 0;
		static int Log_SetCharArrays = 0;
		static bool Log_SetCharEnabled = false;
		static String^ Log_StringText = "";
		//----------
		static std::string SYSTEM_STRING_toSDT_STRING(String^ SYSTEM_STRING)
		{
			std::string STD_string = "";
			msclr::interop::marshal_context context;
			STD_string = context.marshal_as<std::string>(SYSTEM_STRING);
			return STD_string;
		}

		static char* STRING_toCHARPOINTER(std::string SDT_STRING)
		{
			char* STD_charpoint = new char[SDT_STRING.length() + 1];
			strcpy(STD_charpoint, SDT_STRING.c_str());
			return STD_charpoint;
		}
		static String^ SDT_STRING_toSYSTEM_STRING(std::string SDT_STRING)
		{
			String^ SYSTEM_STRING;
			SYSTEM_STRING = gcnew String(SDT_STRING.c_str());
			//Console::WriteLine( << "Functie: \"SDT_STRING_toSYSTEM_STRING\" uitgevoerd.\n";
			return SYSTEM_STRING;
		}
		static char* SYSTEM_STRIN_toCharpoint(String^ SYSTEM_STRING)
		{
			std::string STD_String = SYSTEM_STRING_toSDT_STRING(SYSTEM_STRING);
			return STRING_toCHARPOINTER(STD_String);
		}
		static wchar_t* SYSTEM_STRING_toWchar_tpoint(String^ SYSTEM_STRING)
		{
			char* CharPoint = SYSTEM_STRIN_toCharpoint(SYSTEM_STRING);
			size_t CharPointSize = strlen(CharPoint) + 1;
			wchar_t * Wchar_t = new wchar_t[CharPointSize];
			size_t convertedChars = 0;
			mbstowcs_s(&convertedChars, Wchar_t, CharPointSize, CharPoint, _TRUNCATE);
			if (CharPoint) { delete[] CharPoint; }
			return Wchar_t;
		}
		static String^ Wchar_tPointer_to_SystemString(wchar_t* WCHAR_T_STRING)
		{
			wchar_t *orig = WCHAR_T_STRING;
			size_t origsize = wcslen(orig) + 1;
			size_t convertedChars = 0;
			char strConcat[] = " (char *)";
			size_t strConcatsize = (strlen(strConcat) + 1) * 2;
			const size_t newsize = origsize * 2;
			char *nstring = new char[newsize + strConcatsize];
			wcstombs_s(&convertedChars, nstring, newsize, orig, _TRUNCATE);

			std::string ReturnValue = nstring;
			if (nstring) { delete[] nstring; }
			return SDT_STRING_toSYSTEM_STRING(ReturnValue);
		}
		static void SYSTEM_STRING_toMaxCharLength(int MAX_CHARLENGHT, String^ SYSTEM_STRING, char* DESTINATION)
		{
			//----Only for debuggin (you can see how many bytes the destination char is)
			if (Log_SetCharEnabled == true)
			{
				Log_SetCharSize = sizeof(char);
				Log_SetCharArrays = MAX_CHARLENGHT;
				Log_StringText = SYSTEM_STRING;
			}
			//----------------------
			char * Temp_SourceString = StringConversie::SYSTEM_STRIN_toCharpoint(SYSTEM_STRING);
			int Temp_ValueLength = SYSTEM_STRING->Length;
			int Temp_MaxStringLength = MAX_CHARLENGHT;
			if (Temp_MaxStringLength >= Temp_ValueLength)
			{
				Temp_MaxStringLength = Temp_ValueLength;

			}
			else
			{
				System::Diagnostics::Debug::WriteLine("ERROR: MAX_CHARLENGHT is:" + Temp_MaxStringLength + ". The input string is:" + Temp_ValueLength);
				System::Diagnostics::Debug::WriteLine("The too many characters have been removed");
			}
			
			for (int i = 0; i < MAX_CHARLENGHT; i++)
			{
				if (i < Temp_MaxStringLength )
				{
					DESTINATION[i] = Temp_SourceString[i];
				}
				else
				{
					DESTINATION[i] = '\0';
				}
			}
			
			delete[] Temp_SourceString;
		}
		 
		static void SYSTEM_STRING_toMaxWCharLength(int MAX_CHARLENGHT, String^ SYSTEM_STRING, wchar_t * DESTINATION)
		{
			//----Only for debuggin (you can see how many bytes the destination char is)
			if (Log_SetCharEnabled == true)
			{
				Log_SetCharSize = sizeof(wchar_t);
				Log_SetCharArrays = MAX_CHARLENGHT;
				Log_StringText = SYSTEM_STRING;
			}
			//----------------------
			wchar_t* Temp_SourceString = StringConversie::SYSTEM_STRING_toWchar_tpoint(SYSTEM_STRING);
			int Temp_ValueLength = SYSTEM_STRING->Length;
			int Temp_MaxStringLength = MAX_CHARLENGHT;
			if (Temp_MaxStringLength >= Temp_ValueLength)
			{
				Temp_MaxStringLength = Temp_ValueLength;

			}
			else
			{
				System::Diagnostics::Debug::WriteLine("ERROR: MAX_CHARLENGHT is:" + Temp_MaxStringLength + ". The input string is:" + Temp_ValueLength);
				System::Diagnostics::Debug::WriteLine("The too many characters have been removed");
			}

			for (int i = 0; i < MAX_CHARLENGHT; i++)
			{
				if (i < Temp_MaxStringLength)
				{
					DESTINATION[i] = Temp_SourceString[i];
				}
				else
				{
					DESTINATION[i] = '\0';
				}
			}

			delete[] Temp_SourceString;
		}
		

	};
}