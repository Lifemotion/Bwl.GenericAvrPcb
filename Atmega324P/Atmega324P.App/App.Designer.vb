<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class App
    Inherits Bwl.Framework.FormAppBase

    'Форма переопределяет dispose для очистки списка компонентов.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Является обязательной для конструктора форм Windows Forms
    Private components As System.ComponentModel.IContainer

    'Примечание: следующая процедура является обязательной для конструктора форм Windows Forms
    'Для ее изменения используйте конструктор форм Windows Form.  
    'Не изменяйте ее в редакторе исходного кода.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.bRedOn = New System.Windows.Forms.Button()
        Me.bGreenOn = New System.Windows.Forms.Button()
        Me.bBlueOn = New System.Windows.Forms.Button()
        Me.bRedOff = New System.Windows.Forms.Button()
        Me.bGreenOff = New System.Windows.Forms.Button()
        Me.bBlueOff = New System.Windows.Forms.Button()
        Me.portsList = New System.Windows.Forms.ComboBox()
        Me.bScan = New System.Windows.Forms.Button()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.bOpenPort = New System.Windows.Forms.Button()
        Me.bOpenSSTool = New System.Windows.Forms.Button()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.adcResult0 = New System.Windows.Forms.Label()
        Me.adcResult1 = New System.Windows.Forms.Label()
        Me.adcResult2 = New System.Windows.Forms.Label()
        Me.adcResult3 = New System.Windows.Forms.Label()
        Me.bSw1On = New System.Windows.Forms.Button()
        Me.bSw1Off = New System.Windows.Forms.Button()
        Me.bSw2Off = New System.Windows.Forms.Button()
        Me.bSw2On = New System.Windows.Forms.Button()
        Me.bIRon = New System.Windows.Forms.Button()
        Me.bIRoff = New System.Windows.Forms.Button()
        Me.bRefresh = New System.Windows.Forms.Button()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.SuspendLayout()
        '
        'logWriter
        '
        Me.logWriter.Location = New System.Drawing.Point(2, 244)
        Me.logWriter.Size = New System.Drawing.Size(556, 173)
        '
        'bRedOn
        '
        Me.bRedOn.Location = New System.Drawing.Point(15, 19)
        Me.bRedOn.Name = "bRedOn"
        Me.bRedOn.Size = New System.Drawing.Size(75, 23)
        Me.bRedOn.TabIndex = 2
        Me.bRedOn.Text = "Red On"
        Me.bRedOn.UseVisualStyleBackColor = True
        '
        'bGreenOn
        '
        Me.bGreenOn.Location = New System.Drawing.Point(16, 48)
        Me.bGreenOn.Name = "bGreenOn"
        Me.bGreenOn.Size = New System.Drawing.Size(75, 23)
        Me.bGreenOn.TabIndex = 3
        Me.bGreenOn.Text = "Green On"
        Me.bGreenOn.UseVisualStyleBackColor = True
        '
        'bBlueOn
        '
        Me.bBlueOn.Location = New System.Drawing.Point(16, 77)
        Me.bBlueOn.Name = "bBlueOn"
        Me.bBlueOn.Size = New System.Drawing.Size(75, 23)
        Me.bBlueOn.TabIndex = 4
        Me.bBlueOn.Text = "Blue On"
        Me.bBlueOn.UseVisualStyleBackColor = True
        '
        'bRedOff
        '
        Me.bRedOff.Location = New System.Drawing.Point(96, 19)
        Me.bRedOff.Name = "bRedOff"
        Me.bRedOff.Size = New System.Drawing.Size(75, 23)
        Me.bRedOff.TabIndex = 5
        Me.bRedOff.Text = "Red Off"
        Me.bRedOff.UseVisualStyleBackColor = True
        '
        'bGreenOff
        '
        Me.bGreenOff.Location = New System.Drawing.Point(96, 48)
        Me.bGreenOff.Name = "bGreenOff"
        Me.bGreenOff.Size = New System.Drawing.Size(75, 23)
        Me.bGreenOff.TabIndex = 6
        Me.bGreenOff.Text = "Green Off"
        Me.bGreenOff.UseVisualStyleBackColor = True
        '
        'bBlueOff
        '
        Me.bBlueOff.Location = New System.Drawing.Point(96, 77)
        Me.bBlueOff.Name = "bBlueOff"
        Me.bBlueOff.Size = New System.Drawing.Size(75, 23)
        Me.bBlueOff.TabIndex = 7
        Me.bBlueOff.Text = "Blue Off"
        Me.bBlueOff.UseVisualStyleBackColor = True
        '
        'portsList
        '
        Me.portsList.FormattingEnabled = True
        Me.portsList.Location = New System.Drawing.Point(27, 25)
        Me.portsList.Name = "portsList"
        Me.portsList.Size = New System.Drawing.Size(75, 21)
        Me.portsList.TabIndex = 8
        '
        'bScan
        '
        Me.bScan.Location = New System.Drawing.Point(108, 25)
        Me.bScan.Name = "bScan"
        Me.bScan.Size = New System.Drawing.Size(75, 23)
        Me.bScan.TabIndex = 9
        Me.bScan.Text = "Scan"
        Me.bScan.UseVisualStyleBackColor = True
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.bIRoff)
        Me.GroupBox1.Controls.Add(Me.bIRon)
        Me.GroupBox1.Controls.Add(Me.bRedOn)
        Me.GroupBox1.Controls.Add(Me.bGreenOn)
        Me.GroupBox1.Controls.Add(Me.bBlueOn)
        Me.GroupBox1.Controls.Add(Me.bBlueOff)
        Me.GroupBox1.Controls.Add(Me.bRedOff)
        Me.GroupBox1.Controls.Add(Me.bGreenOff)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 69)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(191, 137)
        Me.GroupBox1.TabIndex = 10
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Module LED Control"
        '
        'bOpenPort
        '
        Me.bOpenPort.Location = New System.Drawing.Point(189, 25)
        Me.bOpenPort.Name = "bOpenPort"
        Me.bOpenPort.Size = New System.Drawing.Size(61, 23)
        Me.bOpenPort.TabIndex = 11
        Me.bOpenPort.Text = "Open"
        Me.bOpenPort.UseVisualStyleBackColor = True
        '
        'bOpenSSTool
        '
        Me.bOpenSSTool.Location = New System.Drawing.Point(256, 25)
        Me.bOpenSSTool.Name = "bOpenSSTool"
        Me.bOpenSSTool.Size = New System.Drawing.Size(75, 23)
        Me.bOpenSSTool.TabIndex = 12
        Me.bOpenSSTool.Text = "SSTool"
        Me.bOpenSSTool.UseVisualStyleBackColor = True
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.adcResult3)
        Me.GroupBox2.Controls.Add(Me.adcResult2)
        Me.GroupBox2.Controls.Add(Me.adcResult1)
        Me.GroupBox2.Controls.Add(Me.adcResult0)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.Label2)
        Me.GroupBox2.Controls.Add(Me.Label1)
        Me.GroupBox2.Location = New System.Drawing.Point(221, 69)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(153, 137)
        Me.GroupBox2.TabIndex = 13
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "ADC results"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.bSw2On)
        Me.GroupBox3.Controls.Add(Me.bSw2Off)
        Me.GroupBox3.Controls.Add(Me.bSw1Off)
        Me.GroupBox3.Controls.Add(Me.bSw1On)
        Me.GroupBox3.Location = New System.Drawing.Point(389, 69)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(149, 137)
        Me.GroupBox3.TabIndex = 14
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Switches"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(6, 24)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(56, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "ADC ch 0:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(6, 53)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(56, 13)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "ADC ch 1:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(6, 111)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(56, 13)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "ADC ch 3:"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(6, 82)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(56, 13)
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "ADC ch 2:"
        '
        'adcResult0
        '
        Me.adcResult0.AutoSize = True
        Me.adcResult0.Location = New System.Drawing.Point(68, 24)
        Me.adcResult0.Name = "adcResult0"
        Me.adcResult0.Size = New System.Drawing.Size(29, 13)
        Me.adcResult0.TabIndex = 4
        Me.adcResult0.Text = "0.0V"
        '
        'adcResult1
        '
        Me.adcResult1.AutoSize = True
        Me.adcResult1.Location = New System.Drawing.Point(68, 53)
        Me.adcResult1.Name = "adcResult1"
        Me.adcResult1.Size = New System.Drawing.Size(29, 13)
        Me.adcResult1.TabIndex = 5
        Me.adcResult1.Text = "0.0V"
        '
        'adcResult2
        '
        Me.adcResult2.AutoSize = True
        Me.adcResult2.Location = New System.Drawing.Point(68, 82)
        Me.adcResult2.Name = "adcResult2"
        Me.adcResult2.Size = New System.Drawing.Size(29, 13)
        Me.adcResult2.TabIndex = 6
        Me.adcResult2.Text = "0.0V"
        '
        'adcResult3
        '
        Me.adcResult3.AutoSize = True
        Me.adcResult3.Location = New System.Drawing.Point(68, 111)
        Me.adcResult3.Name = "adcResult3"
        Me.adcResult3.Size = New System.Drawing.Size(29, 13)
        Me.adcResult3.TabIndex = 7
        Me.adcResult3.Text = "0.0V"
        '
        'bSw1On
        '
        Me.bSw1On.Location = New System.Drawing.Point(6, 19)
        Me.bSw1On.Name = "bSw1On"
        Me.bSw1On.Size = New System.Drawing.Size(63, 23)
        Me.bSw1On.TabIndex = 0
        Me.bSw1On.Text = "SW1 ON"
        Me.bSw1On.UseVisualStyleBackColor = True
        '
        'bSw1Off
        '
        Me.bSw1Off.Location = New System.Drawing.Point(80, 19)
        Me.bSw1Off.Name = "bSw1Off"
        Me.bSw1Off.Size = New System.Drawing.Size(63, 23)
        Me.bSw1Off.TabIndex = 1
        Me.bSw1Off.Text = "SW1 OFF"
        Me.bSw1Off.UseVisualStyleBackColor = True
        '
        'bSw2Off
        '
        Me.bSw2Off.Location = New System.Drawing.Point(80, 77)
        Me.bSw2Off.Name = "bSw2Off"
        Me.bSw2Off.Size = New System.Drawing.Size(63, 23)
        Me.bSw2Off.TabIndex = 2
        Me.bSw2Off.Text = "SW2 OFF"
        Me.bSw2Off.UseVisualStyleBackColor = True
        '
        'bSw2On
        '
        Me.bSw2On.Location = New System.Drawing.Point(6, 77)
        Me.bSw2On.Name = "bSw2On"
        Me.bSw2On.Size = New System.Drawing.Size(63, 23)
        Me.bSw2On.TabIndex = 3
        Me.bSw2On.Text = "SW2 ON"
        Me.bSw2On.UseVisualStyleBackColor = True
        '
        'bIRon
        '
        Me.bIRon.Location = New System.Drawing.Point(15, 106)
        Me.bIRon.Name = "bIRon"
        Me.bIRon.Size = New System.Drawing.Size(75, 23)
        Me.bIRon.TabIndex = 8
        Me.bIRon.Text = "IR On"
        Me.bIRon.UseVisualStyleBackColor = True
        '
        'bIRoff
        '
        Me.bIRoff.Location = New System.Drawing.Point(96, 106)
        Me.bIRoff.Name = "bIRoff"
        Me.bIRoff.Size = New System.Drawing.Size(75, 23)
        Me.bIRoff.TabIndex = 9
        Me.bIRoff.Text = "IR Off"
        Me.bIRoff.UseVisualStyleBackColor = True
        '
        'bRefresh
        '
        Me.bRefresh.Location = New System.Drawing.Point(221, 212)
        Me.bRefresh.Name = "bRefresh"
        Me.bRefresh.Size = New System.Drawing.Size(153, 23)
        Me.bRefresh.TabIndex = 16
        Me.bRefresh.Text = "ADC refresh"
        Me.bRefresh.UseVisualStyleBackColor = True
        '
        'App
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(567, 426)
        Me.Controls.Add(Me.bRefresh)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.bOpenSSTool)
        Me.Controls.Add(Me.bOpenPort)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.bScan)
        Me.Controls.Add(Me.portsList)
        Me.Name = "App"
        Me.Text = "Atmega324P.App"
        Me.Controls.SetChildIndex(Me.logWriter, 0)
        Me.Controls.SetChildIndex(Me.portsList, 0)
        Me.Controls.SetChildIndex(Me.bScan, 0)
        Me.Controls.SetChildIndex(Me.GroupBox1, 0)
        Me.Controls.SetChildIndex(Me.bOpenPort, 0)
        Me.Controls.SetChildIndex(Me.bOpenSSTool, 0)
        Me.Controls.SetChildIndex(Me.GroupBox2, 0)
        Me.Controls.SetChildIndex(Me.GroupBox3, 0)
        Me.Controls.SetChildIndex(Me.bRefresh, 0)
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents bRedOn As Button
    Friend WithEvents bGreenOn As Button
    Friend WithEvents bBlueOn As Button
    Friend WithEvents bRedOff As Button
    Friend WithEvents bGreenOff As Button
    Friend WithEvents bBlueOff As Button
    Friend WithEvents portsList As ComboBox
    Friend WithEvents bScan As Button
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents bOpenPort As Button
    Friend WithEvents bOpenSSTool As Button
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents adcResult3 As Label
    Friend WithEvents adcResult2 As Label
    Friend WithEvents adcResult1 As Label
    Friend WithEvents adcResult0 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label1 As Label
    Friend WithEvents GroupBox3 As GroupBox
    Friend WithEvents bSw2On As Button
    Friend WithEvents bSw2Off As Button
    Friend WithEvents bSw1Off As Button
    Friend WithEvents bSw1On As Button
    Friend WithEvents bIRoff As Button
    Friend WithEvents bIRon As Button
    Friend WithEvents bRefresh As Button
End Class
