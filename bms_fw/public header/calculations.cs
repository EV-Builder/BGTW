if (msg.ID == 0x600)
            {
                fieldnr = Convert.ToInt32(msg.DATA[0]);

                dgvBMS.Rows[PACKVOLTS].Cells[fieldnr + 1].Value = FormatS((((msg.DATA[2] << 8) + msg.DATA[3])  * 24.4414) /10000);
                dgvBMS.Rows[TCHIP].Cells[fieldnr + 1].Value = FormatS(((((msg.DATA[4] << 8) + msg.DATA[5]) * 32) /1000.0) -273.0);

            }
            else if (msg.ID == 0x601)
            {
                dgvBMS.Rows[CELL1].Cells[fieldnr + 1].Value = FormatS(( ( (msg.DATA[0] << 8) + msg.DATA[1]) * 1.5259) / 10000);
                dgvBMS.Rows[CELL2].Cells[fieldnr + 1].Value = FormatS(( ((msg.DATA[2] << 8) + msg.DATA[3]) * 1.5259) / 10000);
                dgvBMS.Rows[CELL3].Cells[fieldnr + 1].Value = FormatS(( ((msg.DATA[4] << 8) + msg.DATA[5]) * 1.5259) / 10000);
                dgvBMS.Rows[CELL4].Cells[fieldnr + 1].Value = FormatS(( ((msg.DATA[6] << 8) + msg.DATA[7]) * 1.5259) / 10000);
            }
            else if (msg.ID == 0x602) {
                dgvBMS.Rows[CELL5].Cells[fieldnr + 1].Value = FormatS(( ((msg.DATA[0] << 8) + msg.DATA[1]) * 1.5259) / 10000);
                dgvBMS.Rows[CELL6].Cells[fieldnr + 1].Value = FormatS(( ((msg.DATA[2] << 8) + msg.DATA[3]) * 1.5259) / 10000);

                Int32 ti32 = 0;
                byte[] barr;
                barr = msg.DATA;

                ti32 = BitConverter.ToInt32(barr, 4);

                dgvBMS.Rows[CURRENT].Cells[fieldnr + 1].Value = FormatS((ti32 * 6) / 1000);

            }
            else if (msg.ID == 0x603)
            {
                int mux = msg.DATA[0];


                //int temp = ((msg.DATA[0] << 8) + msg.DATA[1]);
                //dgvBMS.Rows[ANCELL1].Cells[fieldnr + 1].Value = FormatS((temp * 1.5259) / 10000);

                int temp = ((msg.DATA[2] << 8) + msg.DATA[3]);

                if (mux == 1)
                {
                    dgvBMS.Rows[ANCELL1].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                    temp = ((msg.DATA[4] << 8) + msg.DATA[5]);
                    dgvBMS.Rows[ANCELL2].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                    temp = ((msg.DATA[6] << 8) + msg.DATA[7]);
                    dgvBMS.Rows[ANCELL3].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                } else if (mux == 2)
                {
                    dgvBMS.Rows[ANCELL4].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                    temp = ((msg.DATA[4] << 8) + msg.DATA[5]);
                    dgvBMS.Rows[ANCELL5].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                    temp = ((msg.DATA[6] << 8) + msg.DATA[7]);
                    dgvBMS.Rows[ANCELL6].Cells[fieldnr + 1].Value = FormatS( (temp * 1.5259) / 10000);

                } else if (mux == 3)
                {
                    temp = ((msg.DATA[2] << 8) + msg.DATA[3]);
                    dgvBMS.Rows[CCSamples].Cells[fieldnr + 1].Value = temp.ToString();

                    Int32 ti32 = 0;
                    byte[] barr;
                    barr = msg.DATA;

                    ti32 = BitConverter.ToInt32(barr, 4);

                    dgvBMS.Rows[CCounter].Cells[fieldnr + 1].Value = ti32;

                }

            }
            else if (msg.ID == 0x604)
            {
                
            }