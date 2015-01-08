using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PlanvsActual
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        Socket clientConnection;
        static AutoResetEvent waitEvent;


 
        public MainWindow()
        {
            InitializeComponent();

            waitEvent = new AutoResetEvent(false);           
        }


        
        private void ModelTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void PlanTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {


        }

        private void SetBtn_Click(object sender, RoutedEventArgs e)
        {
            String model = ModelTextBox.Text;
            String planQty = PlanTextBox.Text;

            int result;

            if (model.Length == 0 || planQty.Length == 0)
            {
                MessageBox.Show("Invalid data",
                    "Application Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            if (!int.TryParse(PlanTextBox.Text, out result))
            {
                PlanTextBox.Clear();
                MessageBox.Show("Invalid plan",
                        "Application Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            try
            {

                String ipAddress = ConfigurationSettings.AppSettings["IP"];
                int port = Convert.ToInt32(ConfigurationSettings.AppSettings["PORT"]);
                clientConnection = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                System.Net.IPAddress ipaddr = System.Net.IPAddress.Parse(ipAddress);
                clientConnection.Connect(ipAddress, port);
            }
            catch (Exception s)
            {
                MessageBox.Show("Connection failed, Please verify the connection", "Connection Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            //Convert to upper case
            model = model.ToUpper();

            //Send model name
            byte[] modelBytes = System.Text.Encoding.ASCII.GetBytes(model);
            List<Byte> byteList = new List<byte>();

            byteList.Add(0x80);
            byteList.AddRange(modelBytes);

            clientConnection.Send(byteList.ToArray());
            waitEvent.WaitOne(500);

            //Send plan qty
            byte[] planQtyBytes = System.Text.Encoding.ASCII.GetBytes(planQty);
            List<Byte> PlanQtybyteList = new List<byte>();

            PlanQtybyteList.Add(0x81);
            PlanQtybyteList.AddRange(planQtyBytes);

            clientConnection.Send(PlanQtybyteList.ToArray());
            waitEvent.WaitOne(500);

            MessageBox.Show("Command sent",
                        "Application Info", MessageBoxButton.OK, MessageBoxImage.Information);
            clientConnection.Close();
        }

        private void ModifyBtn_Click_1(object sender, RoutedEventArgs e)
        {
            String planQty = PlanTextBox.Text;
            int result;

            if (planQty.Length == 0)
            {
                MessageBox.Show("Invalid Plan Quantity",
                        "Application Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            if (!int.TryParse(PlanTextBox.Text, out result))
            {
                PlanTextBox.Clear();
                MessageBox.Show("Invalid plan",
                        "Application Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            try
            {

                String ipAddress = ConfigurationSettings.AppSettings["IP"];
                int port = Convert.ToInt32(ConfigurationSettings.AppSettings["PORT"]);
                clientConnection = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                System.Net.IPAddress ipaddr = System.Net.IPAddress.Parse(ipAddress);
                clientConnection.Connect(ipAddress, port);
            }
            catch (Exception s)
            {
                MessageBox.Show("Connection failed, Please verify the connection", "Connection Info", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            byte[] bytes = System.Text.Encoding.ASCII.GetBytes(planQty);
            List<Byte> byteList = new List<byte>();

            byteList.Add(0x82);
            byteList.AddRange(bytes);

            clientConnection.Send(byteList.ToArray());
            waitEvent.WaitOne(500);

            MessageBox.Show("Command sent",
            "Application Info", MessageBoxButton.OK, MessageBoxImage.Information);
            clientConnection.Close();
        }

        private void ConnectBtn_Click(object sender, RoutedEventArgs e)
        {


        }
    }
}
