Imports Bwl.Hardware.SimplSerial

Public Class App

    Private _ssb As New SimplSerialBus()

    Private Sub PortsListRefresh()
        Dim ports As String() = IO.Ports.SerialPort.GetPortNames()
        portsList.Items.Clear()
        For Each port As String In ports
            portsList.Items.Add(port)
        Next
        _logger.AddMessage("Ports count: " + ports.Length.ToString)
    End Sub

    Private Sub App_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        PortsListRefresh()
    End Sub

    Private Sub bScan_Click(sender As Object, e As EventArgs) Handles bScan.Click
        PortsListRefresh()
    End Sub

    Private Sub bOpenPort_Click(sender As Object, e As EventArgs) Handles bOpenPort.Click
        If portsList.SelectedItem = Nothing Then Return
        _ssb.SerialDevice.DeviceAddress = portsList.SelectedItem.ToString()
        _ssb.SerialDevice.DeviceSpeed = 9600
        _ssb.Connect()
        _logger.AddMessage(_ssb.RequestDeviceInfo(0).DeviceName)
    End Sub

    Private Sub bRedOn_Click(sender As Object, e As EventArgs) Handles bRedOn.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 1, {1})
        _logger.AddMessage("Red LED is on")
    End Sub

    Private Sub bRedOff_Click(sender As Object, e As EventArgs) Handles bRedOff.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 1, {0})
        _logger.AddMessage("Red LED is off")
    End Sub

    Private Sub bGreenOn_Click(sender As Object, e As EventArgs) Handles bGreenOn.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 2, {1})
        _logger.AddMessage("Green LED is on")
    End Sub

    Private Sub bGreenOff_Click(sender As Object, e As EventArgs) Handles bGreenOff.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 2, {0})
        _logger.AddMessage("Green LED is off")
    End Sub

    Private Sub bBlueOn_Click(sender As Object, e As EventArgs) Handles bBlueOn.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 3, {1})
        _logger.AddMessage("Blue LED is on")
    End Sub

    Private Sub bBlueOff_Click(sender As Object, e As EventArgs) Handles bBlueOff.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 3, {0})
        _logger.AddMessage("Blue LED is off")
    End Sub

    Private Sub bOpenSSTool_Click(sender As Object, e As EventArgs) Handles bOpenSSTool.Click
        If Not _ssb.IsConnected Then Return
        Dim sst As New SimplSerialTool(_ssb)
        sst.Show()
    End Sub

    Private Sub bIRon_Click(sender As Object, e As EventArgs) Handles bIRon.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 4, {1})
        _logger.AddMessage("IR LED is on")
    End Sub

    Private Sub bIRoff_Click(sender As Object, e As EventArgs) Handles bIRoff.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 4, {0})
        _logger.AddMessage("IR LED is off")
    End Sub

    Private Sub bSw1On_Click(sender As Object, e As EventArgs) Handles bSw1On.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 5, {1})
        _logger.AddMessage("Switch 1 is on")
    End Sub

    Private Sub bSw1Off_Click(sender As Object, e As EventArgs) Handles bSw1Off.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 5, {0})
        _logger.AddMessage("Switch 1 is off")
    End Sub

    Private Sub bSw2On_Click(sender As Object, e As EventArgs) Handles bSw2On.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 6, {1})
        _logger.AddMessage("Switch 2 is on")
    End Sub

    Private Sub bSw2Off_Click(sender As Object, e As EventArgs) Handles bSw2Off.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 6, {0})
        _logger.AddMessage("Switch 2 is off")
    End Sub

    Private Sub bRefresh_Click(sender As Object, e As EventArgs) Handles bRefresh.Click
        If Not _ssb.IsConnected Then Return
        Dim resp = _ssb.Request(0, 7)
        adcResult0.Text = Math.Round((resp.Data(0) * 256 + resp.Data(1)) * 1.1 / 1024.0, 2).ToString + "V"
        adcResult1.Text = Math.Round((resp.Data(2) * 256 + resp.Data(3)) * 1.1 / 1024.0, 2).ToString + "V"
        adcResult2.Text = Math.Round((resp.Data(4) * 256 + resp.Data(5)) * 1.1 / 1024.0, 2).ToString + "V"
        adcResult3.Text = Math.Round((resp.Data(6) * 256 + resp.Data(7)) * 1.1 / 1024.0, 2).ToString + "V"
    End Sub
End Class
